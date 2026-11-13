//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include <vector>
#include "clase.h"
#include "Grafo.h"
#include "Ruta.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *gridCiudades;
	TLabel *ID;
	TLabel *Y;
	TLabel *X;
	TLabel *Nombre;
	TEdit *editID;
	TEdit *editNombre;
	TEdit *editX;
	TEdit *editY;
	TButton *btnAgregar;
	TButton *btnEliminar;
	TButton *btnModificar;
	TImage *Image1;
	TPanel *Panel1;
	TPanel *Panel2;
	TStringGrid *gridRutas;
	TComboBox *cmbOrigen;
	TComboBox *cmbDestino;
	TEdit *editDistancia;
	TButton *btnCargarRuta;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnAgregarClick(TObject *Sender);
	void __fastcall gridCiudadesSelectCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          bool &CanSelect);
	void __fastcall btnEliminarClick(TObject *Sender);
	void __fastcall btnModificarClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCargarRutaClick(TObject *Sender);
	//void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);

private:

    std::vector<Ciudad> vector_ciudades;
	Grafo mi_grafo;
    void ActualizarGridRutas();
	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
