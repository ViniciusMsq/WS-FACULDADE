unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, Buttons, Math;

type
  TForm1 = class(TForm)
    lblR: TLabel;
    lblG: TLabel;
    lblB: TLabel;
    img1: TImage;
    BitBtn1: TBitBtn;
    G: TLabel;
    R: TLabel;
    B: TLabel;
    imgR: TImage;
    imgB: TImage;
    imgG: TImage;
    imgBranco: TImage;
    BitBtn2: TBitBtn;
    edtX1: TEdit;
    edtY1: TEdit;
    edtX2: TEdit;
    edtY2: TEdit;
    procedure img1MouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure img1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure BitBtn1Click(Sender: TObject);
    procedure BitBtn2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.img1MouseMove(Sender: TObject; Shift: TShiftState; X,
  Y: Integer);
begin
    lblR.Caption := intToStr(
      getRValue(img1.canvas.Pixels[x,y]));
    lblG.Caption := intToStr(
      getGValue(img1.canvas.Pixels[x,y]));
    lblB.Caption := intToStr(
      getBValue(img1.canvas.Pixels[x,y]));
end;

procedure TForm1.img1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  img1.Canvas.pixels[x,y] := RGB(0,0,0);
end;

procedure TForm1.BitBtn1Click(Sender: TObject);
var x, y, cor : integer;
begin
  for x := 0 to img1.width -1 do
      for y := 0 to img1.height -1 do
      begin
        //RED
        cor := getRValue(img1.Canvas.Pixels[x,y]);
        imgR.Canvas.Pixels[x,y] := RGB(cor, 0, 0);
        //GREEN
        cor := getGValue(img1.Canvas.Pixels[x,y]);
        imgG.Canvas.Pixels[x,y] := RGB(0, cor, 0);
        //BLUE
        cor := getBValue(img1.Canvas.Pixels[x,y]);
        imgB.Canvas.Pixels[x,y] := RGB(0, 0, cor);
      end;
end;

procedure TForm1.BitBtn2Click(Sender: TObject);
var i, x1, y1, x2, y2, length : integer; x, y, dx, dy : double;
begin
  x1:= strToInt(edtX1.Text);
  y1:= strToInt(edtY1.Text);
  x2:= strToInt(edtX2.Text);
  y2:= strToInt(edtY2.Text);

  if (abs(x2 - x1) >= abs(y2 - y1)) then
    length := abs(x2 - x1)
  else
     length := abs(y2 - y1);

  dx := (x2 - x1) / length;
  dy := (y2 - y1) / length;

  x := x1 + 0.5;
  y := y1 + 0.5;

  for i := 1 to length do
  begin
     imgBranco.Canvas.Pixels[trunc(x), trunc(y)] := RGB(0,0,0);
     x := x + dx;
     y := y + dy;
  end;

end;

end.
