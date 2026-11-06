//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

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
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnAgregarClick(TObject *Sender);
	void __fastcall gridCiudadesSelectCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
          bool &CanSelect);
	void __fastcall btnEliminarClick(TObject *Sender);
	void __fastcall btnModificarClick(TObject *Sender);
private:

    std::vector<Ciudad> vector_ciudades;
	Grafo mi_grafo;
	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
