//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Form.h"
#include "clase.h"
#include "Grafo.h"
#include "Ruta.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
		SetCurrentDir("..\\..");
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	this->Caption = "Sistema Inteligente de Gestión Logística y Optimización de Rutas";
	gridCiudades->ColWidths[0] = 40;  //id
	gridCiudades->ColWidths[1] = 120; //nombre
	gridCiudades->ColWidths[2] = 100; //coordenada X
	gridCiudades->ColWidths[3] = 100; //coordenada Y

    //títulos de las columnas
	gridCiudades->Cells[0][0] = "ID";
	gridCiudades->Cells[1][0] = "Nombre";
	gridCiudades->Cells[2][0] = "Coordenada X";
	gridCiudades->Cells[3][0] = "Coordenada Y";

	//cargamos las ciudades
	vector_ciudades = Ciudad::leerArchivo();

	if (mi_grafo.obtener_cantidad_de_ciudades() == 0)
	{
		for (size_t i = 0; i < vector_ciudades.size(); i++)
		{
			mi_grafo.agregar_ciudad();
		}
		mi_grafo.leerRuta();
	}

	//las ordenamos
	//Ciudad::OrdenarPorID(vector_ciudades);

    //limpiamos los desplegables para elegir ciudad origen/destino
	cmbOrigen->Items->Clear();
	cmbDestino->Items->Clear();

		//llenamos la grilla si hay datos
	if (!vector_ciudades.empty())
	{
		gridCiudades->RowCount = vector_ciudades.size() + 1;
		for (size_t i = 0; i < vector_ciudades.size(); i++)
		{
			String nombreCiudad = String(vector_ciudades[i].getNombre().c_str());

			gridCiudades->Cells[0][i + 1] = IntToStr(vector_ciudades[i].getID());
			gridCiudades->Cells[1][i + 1] = String(vector_ciudades[i].getNombre().c_str());
            gridCiudades->Cells[2][i + 1] = IntToStr(vector_ciudades[i].getX());
			gridCiudades->Cells[3][i + 1] = IntToStr(vector_ciudades[i].getY());

            cmbOrigen->Items->Add(nombreCiudad);
			cmbDestino->Items->Add(nombreCiudad);
        }
	}
	else
	{
		gridCiudades->RowCount = 2;
		gridCiudades->Cells[0][0] = "";
		gridCiudades->Cells[0][1] = "";
		gridCiudades->Cells[0][2] = "";
		gridCiudades->Cells[0][3] = "";
	}
	ActualizarGridRutas();
}

void __fastcall TForm1::btnAgregarClick(TObject *Sender)
{
		int id = editID->Text.ToIntDef(-1);
        AnsiString nombre = editNombre->Text;
		int x = editX->Text.ToIntDef(-1);
		int y = editY->Text.ToIntDef(-1);


		if (id < 0 || nombre=="" || x < 0 || y < 0)
		{
			ShowMessage("Por favor ingrese valores/nombres validos.");
			return;
		}

		Ciudad instanciar(id, x, y, std::string(nombre.c_str()));
		instanciar.escribir();

		vector_ciudades.push_back(instanciar);

		mi_grafo.agregar_ciudad();
        mi_grafo.guardarRuta();

		int nuevaFila = vector_ciudades.size();
		gridCiudades->RowCount = nuevaFila + 1;
		gridCiudades->Cells[0][nuevaFila] = IntToStr(instanciar.getID());
		gridCiudades->Cells[1][nuevaFila] = String(instanciar.getNombre().c_str());
		gridCiudades->Cells[2][nuevaFila] = IntToStr(instanciar.getX());
		gridCiudades->Cells[3][nuevaFila] = IntToStr(instanciar.getY());


		editID->Text="";
		editNombre->Text="";
		editX->Text="";
		editY->Text="";
		ActualizarGridRutas();
		cmbOrigen->Items->Add(nombre);
		cmbDestino->Items->Add(nombre);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::gridCiudadesSelectCell(TObject *Sender, System::LongInt ACol,
          System::LongInt ARow, bool &CanSelect)
{
		//si hacemos clic en los titulos no hacemos nada
		if (ARow == 0)
		return;

		//si la fila esta vacia salimos
	if (gridCiudades->Cells[0][ARow] == "")
	{
		//limpiamos
		editID->Text = "";
		editNombre->Text = "";
		editX->Text = "";
		editY->Text = "";
		return;
	}

	//copiamos los datos de la fila seleccionada a las cajas de texto
	editID->Text = gridCiudades->Cells[0][ARow];
	editNombre->Text = gridCiudades->Cells[1][ARow];
	editX->Text = gridCiudades->Cells[2][ARow];
	editY->Text = gridCiudades->Cells[3][ARow];


}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnEliminarClick(TObject *Sender)
{
	int id = editID->Text.ToIntDef(-1);
	if (id == -1)
	return;

	for (int i = 0; i < vector_ciudades.size(); i++)
	{
		if (vector_ciudades[i].getID() == id)
		{
			vector_ciudades.erase(vector_ciudades.begin() + i);
			Ciudad::reescribrir(vector_ciudades);

			mi_grafo.eliminar_ciudad(i);
			mi_grafo.guardarRuta();

			ShowMessage("Ciudad eliminada.");
			FormCreate(this);
			ActualizarGridRutas();
			return;
		}
	}
	ShowMessage("No se encontró una ciudad con ese ID.");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnModificarClick(TObject *Sender)
{
	int id = editID->Text.ToIntDef(-1);
	int x = editX->Text.ToIntDef(-1);
	int y = editY->Text.ToIntDef(-1);
	AnsiString ciudadNombre = editNombre->Text;

	if (id < 0 || ciudadNombre == "" || x < 0 || y < 0)
	{
		ShowMessage("Por favor ingrese valores/nombres validos.");
		return;
	}

	for (size_t i = 0; i < vector_ciudades.size(); i++)
	{
		if (vector_ciudades[i].getID() == id)
		{
			vector_ciudades[i].setNombre(std::string(ciudadNombre.c_str()));
			vector_ciudades[i].setX(x);
			vector_ciudades[i].setY(y);

			Ciudad::reescribrir(vector_ciudades);

			ShowMessage("Ciudad modificada con exito.");
			FormCreate(this);
			return;
		}
	}
	ShowMessage("No se encontró una ciudad con ese ID.");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormResize(TObject *Sender)
{
	//tamaño al 70% de la ventana actual
	Panel1->Width = this->ClientWidth * 0.7;
	Panel1->Height = this->ClientHeight * 0.7;

	//queda en el centro
    Panel1->Left = (this->ClientWidth - Panel1->Width) / 2;
	Panel1->Top = (this->ClientHeight - Panel1->Height) / 2;

    //adaptamos el ancho de las columnas
	if (gridCiudades->Width > 25)
	{
        gridCiudades->DefaultColWidth = (gridCiudades->Width - 25) / 4;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
    FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ActualizarGridRutas()
{
	int n = vector_ciudades.size();

	if (n == 0)
	{
		gridRutas->RowCount = 2;
		gridRutas->ColCount = 2;
		gridRutas->Cells[0][0] = "";
		gridRutas->Cells[1][0] = "";
		gridRutas->Cells[0][1] = "";
		gridRutas->Cells[1][1] = "";
		return;
	}

	gridRutas->ColCount = n + 1;
	gridRutas->RowCount = n + 1;
	gridRutas->Cells[0][0] = "Origen \\ Destino";

	// Encabezados de filas y columnas con los nombres de las ciudades
	for (int i = 0; i < n; i++)
	{
		String nombre = String(vector_ciudades[i].getNombre().c_str());
		gridRutas->Cells[i + 1][0] = nombre; // Columna
		gridRutas->Cells[0][i + 1] = nombre; // Fila
	}

	// Llenar distancias desde la matriz de mi_grafo
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Ruta r = mi_grafo.getRuta(i, j);
			if (i == j)
				gridRutas->Cells[j + 1][i + 1] = "-";
			else if (r.getruta_existe())
				gridRutas->Cells[j + 1][i + 1] = FloatToStr(r.getdistancia()) + " km";
			else
				gridRutas->Cells[j + 1][i + 1] = "0";
		}
	}
}

void __fastcall TForm1::btnCargarRutaClick(TObject *Sender)
{
	int origen = cmbOrigen->ItemIndex;
	int destino = cmbDestino->ItemIndex;
	double distancia = StrToFloatDef(editDistancia->Text, -1);

	if (origen == -1 || destino == -1)
	{
		ShowMessage("Selecciona una ciudad de origen y una de destino.");
		return;
	}
	if (origen == destino)
	{
		ShowMessage("La ciudad de origen y destino no pueden ser la misma.");
		return;
	}
	if (distancia <= 0)
	{
		ShowMessage("Distancia invalida");
		return;
	}

	//creamos ruta
	Ruta ruta_ida(origen, destino, distancia, true, true);
	mi_grafo.set_ruta(origen, destino, ruta_ida);

	Ruta ruta_vuelta(destino, origen, distancia, true, true);
	mi_grafo.set_ruta(destino, origen, ruta_vuelta);

	//guardamos en rutas.bin y reescribimos la matriz
	mi_grafo.guardarRuta();
	ActualizarGridRutas();

	editDistancia->Text = "";
	ShowMessage("Ruta cargada exitosamente.");
}
//---------------------------------------------------------------------------

