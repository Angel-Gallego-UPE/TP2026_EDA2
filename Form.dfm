object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object ID: TLabel
    Left = 88
    Top = 168
    Width = 17
    Height = 17
    Caption = 'ID'
  end
  object Y: TLabel
    Left = 520
    Top = 168
    Width = 7
    Height = 15
    Caption = 'Y'
  end
  object X: TLabel
    Left = 386
    Top = 168
    Width = 7
    Height = 15
    Caption = 'X'
  end
  object Nombre: TLabel
    Left = 224
    Top = 168
    Width = 44
    Height = 15
    Caption = 'Nombre'
  end
  object gridCiudades: TStringGrid
    Left = 88
    Top = 24
    Width = 449
    Height = 120
    ColCount = 4
    FixedCols = 0
    RowCount = 2
    TabOrder = 0
  end
  object editID: TEdit
    Left = 40
    Top = 191
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'editID'
  end
  object editNombre: TEdit
    Left = 179
    Top = 189
    Width = 121
    Height = 23
    TabOrder = 2
    Text = 'editNombre'
  end
  object editX: TEdit
    Left = 327
    Top = 189
    Width = 121
    Height = 23
    TabOrder = 3
    Text = 'editX'
  end
  object editY: TEdit
    Left = 464
    Top = 189
    Width = 121
    Height = 23
    TabOrder = 4
    Text = 'editY'
  end
  object btnAgregar: TButton
    Left = 224
    Top = 264
    Width = 169
    Height = 73
    Caption = 'Agregar ciudad'
    TabOrder = 5
    OnClick = btnAgregarClick
  end
end
