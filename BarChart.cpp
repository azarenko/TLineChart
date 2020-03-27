//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "BarChart.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TBarChart *)
{
        new TBarChart(NULL);
}
//---------------------------------------------------------------------------
__fastcall TBarChart::TBarChart(TComponent* Owner)
        : TGraphicControl(Owner)
{
}
//---------------------------------------------------------------------------
namespace Barchart
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TBarChart)};
                 RegisterComponents("Samples", classes, 0);
        }
}
//---------------------------------------------------------------------------
void __fastcall TBarChart::Paint()
{
        // Fill background
        this->Canvas->Brush->Color = clWhite;
        this->Canvas->Pen->Color = clBlack;
        this->Canvas->Pen->Style = TPenStyle();
        this->Canvas->Pen->Width = 2;
        this->Canvas->Rectangle(1,1,this->Width,this->Height);

        // Draw grid
        float _kx = this->Width / 10.0;
        float _ky = this->Height / 10.0;
        this->Canvas->Pen->Color = clGray;
        this->Canvas->Pen->Width = 1;
        this->Canvas->Pen->Style = psDot;
        for(int i = 1; i < 10; i++)
        {
                // X
                this->Canvas->MoveTo(i * _kx + 1, 1);
                this->Canvas->LineTo(i * _kx + 1,this->Height);
                // Y
                this->Canvas->MoveTo(1, i * _ky + 1);
                this->Canvas->LineTo(this->Width, i * _ky + 1);
        }

        if(this->Lines.size() == 0)
                return;

        // Draw lines
        this->Canvas->Pen->Style = TPenStyle();
        int _x = this->Width / (this->Lines.size() * 2 + 1);
        for(int i = 0; i < this->Lines.size(); i++)
        {
                double _ky = this->Height / this->Lines[i]->Gain ;
                this->Canvas->Brush->Color = this->Lines[i]->Color;

                this->Canvas->Rectangle(_x * (i * 2 + 1), this->Height,
                _x * (i * 2 + 2), this->Height - this->Lines[i]->Data * _ky);
        }
}
//---------------------------------------------------------------------------