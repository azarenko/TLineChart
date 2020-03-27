//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "LineChart.h"
#include "BarChart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
LineItem lines[3];
BarItem blines[3];
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    this->DoubleBuffered = true;

    TLineChart *chart = new TLineChart(this);
    chart->Parent = this;
    chart->Left = 10;
    chart->Top = 10;
    chart->Width = 600;
    chart->Height = 230;
    chart->Anchors = TAnchors() << akLeft << akTop << akRight ;
    chart->DontMoveLines = true;
    chart->DontShowMarkers = true;

    lines[0].Data = new double[100];
    lines[1].Data = new double[100];
    lines[2].Data = new double[100];

    lines[0].Width = 2;
    lines[1].Width = 2;
    lines[2].Width = 2;

    lines[0].Color = clRed;
    lines[1].Color = clBlue;
    lines[2].Color = clGreen;

    lines[0].Gain = 160.0;
    lines[1].Gain = 160.0;
    lines[2].Gain = 160.0;

    lines[0].Scale = 1.0;
    lines[1].Scale = 1.0;
    lines[2].Scale = 1.0;

    lines[0].Divide = 1.0;
    lines[1].Divide = 1.0;
    lines[2].Divide = 1.0;

    lines[0].MarkPoint = true;
    lines[1].MarkPoint = true;
    lines[2].MarkPoint = true;

    //lines[0].Offest = 25.0;
    //lines[1].Offest = 50.0;
    //lines[2].Offest = -100.0;

    for(int i = 0; i < 100; i++)
    {
        lines[0].Data[i] = random(40) - 20.0;
        lines[1].Data[i] = random(40) - 20.0;
        lines[2].Data[i] = random(40) - 20.0;
    }

    chart->Lines.push_back(&lines[0]);
    chart->Lines.push_back(&lines[1]);
    chart->Lines.push_back(&lines[2]);

    chart->Seamples = 100;

    blines[0].Color = clRed;
    blines[1].Color = clBlue;
    blines[2].Color = clGreen;

    blines[0].Gain = 4.0;
    blines[1].Gain = 6.0;
    blines[2].Gain = 1.5;

    blines[0].Data = 2.0;
    blines[1].Data = 5.0;
    blines[2].Data = 1.0;

    TBarChart *bar = new TBarChart(this);
    bar->Parent = this;
    bar->Left = 10;
    bar->Top = 250;
    bar->Width = 300;
    bar->Height = 200;
    bar->Anchors = TAnchors() << akLeft << akTop << akRight;

    bar->Lines.push_back(&blines[0]);
    bar->Lines.push_back(&blines[1]);
    bar->Lines.push_back(&blines[2]);

    chart->OnChange = &this->OnChange;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnChange(TObject* Sender)
{
        this->Label1->Caption = IntToStr(lines[0].Offest);
}
//---------------------------------------------------------------------------


