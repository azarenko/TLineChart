//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "LineChart.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TLineChart *)
{
        new TLineChart(NULL);
}
//---------------------------------------------------------------------------
__fastcall TLineChart::TLineChart(TComponent* Owner)
        : TGraphicControl(Owner)
{
        // Set defaults
        this->MarkerA.Color = clRed;
        this->MarkerB.Color = clBlue;
        this->MarkerC.Color = clGreen;
        this->MarkerD.Color = (TColor)0x00012345;

        this->MarkerA.RealPosition = 50;
        this->MarkerB.RealPosition = 100;
        this->MarkerC.RealPosition = 50;
        this->MarkerD.RealPosition = 100;
}
//---------------------------------------------------------------------------
namespace Linechart
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TLineChart)};
                 RegisterComponents("Samples", classes, 0);
        }
}
//---------------------------------------------------------------------------
void __fastcall TLineChart::Paint()
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

        // Draw lines
        if(!this->Lines.empty())
        {
                double _kx = this->Width / (double)this->Seamples;
                int _zero = this->Height / 2;

                vector<LineItem*>::iterator p;
                p = this->Lines.begin();
                while(p != this->Lines.end())
                {
                        double _ky = this->Height / (*p)->Gain ;
                        this->Canvas->Pen->Style = psDash;
                        this->Canvas->Pen->Width = 1;
                        this->Canvas->Pen->Color = (*p)->Color;
                        this->Canvas->Brush->Color = clWhite;

                        this->Canvas->MoveTo(0, _zero - (*p)->Offest - this->_VerticalOffset);
                        this->Canvas->LineTo(this->Width, _zero - (*p)->Offest - this->_VerticalOffset);
                        this->Canvas->Pen->Style = TPenStyle();
                        this->Canvas->Pen->Width = (*p)->Width;
                        this->Canvas->MoveTo(0, _zero - (((*p)->Data[0] * (*p)->Scale) / (*p)->Divide) * _ky - (*p)->Offest - this->_VerticalOffset);
                        this->Canvas->Brush->Color = (*p)->Color;
                        for(int i = 1; i < this->Seamples; i++)
                        {
                            int x =  i * _kx;
                            int y =  _zero - (((*p)->Data[i] * (*p)->Scale) / (*p)->Divide) * _ky - (*p)->Offest - this->_VerticalOffset;
                            this->Canvas->LineTo(x, y);
                            if((*p)->MarkPoint)
                                this->Canvas->Ellipse(x - 3,
                                y - 3,
                                x + 3,
                                y + 3);
                        }
                        
                        p++;
                }
        }

        if(!this->DontShowMarkers)
        {
        // Draw markers
        // A
        this->Canvas->Pen->Style = TPenStyle();
        this->Canvas->Pen->Color = this->MarkerA.Color;
        this->Canvas->Pen->Width = 1;
        this->Canvas->MoveTo(this->MarkerA.RealPosition, 0);
        this->Canvas->LineTo(this->MarkerA.RealPosition, this->Height);

        this->Canvas->Brush->Color = this->MarkerA.Color;
        this->Canvas->Ellipse(this->MarkerA.RealPosition - 5,
        -2,
        this->MarkerA.RealPosition + 5,
        8);

        // B
        this->Canvas->Pen->Style = TPenStyle();
        this->Canvas->Pen->Color = this->MarkerB.Color;
        this->Canvas->Pen->Width = 1;
        this->Canvas->MoveTo(this->MarkerB.RealPosition, 0);
        this->Canvas->LineTo(this->MarkerB.RealPosition, this->Height);

        this->Canvas->Brush->Color = this->MarkerB.Color;
        this->Canvas->Ellipse(this->MarkerB.RealPosition - 5,
        this->Height - 8,
        this->MarkerB.RealPosition + 5,
        this->Height + 2);

        // C
        this->Canvas->Pen->Style = TPenStyle();
        this->Canvas->Pen->Color = this->MarkerC.Color;
        this->Canvas->Pen->Width = 1;
        this->Canvas->MoveTo(0, this->MarkerC.RealPosition);
        this->Canvas->LineTo(this->Width, this->MarkerC.RealPosition);

        this->Canvas->Brush->Color = this->MarkerC.Color;
        this->Canvas->Ellipse(-2,
        this->MarkerC.RealPosition - 5,
        8,
        this->MarkerC.RealPosition + 5);

        // D
        this->Canvas->Pen->Style = TPenStyle();
        this->Canvas->Pen->Color = this->MarkerD.Color;
        this->Canvas->Pen->Width = 1;
        this->Canvas->MoveTo(0, this->MarkerD.RealPosition);
        this->Canvas->LineTo(this->Width, this->MarkerD.RealPosition);

        this->Canvas->Brush->Color = this->MarkerD.Color;
        this->Canvas->Ellipse(this->Width - 8,
        this->MarkerD.RealPosition - 5,
        this->Width + 2,
        this->MarkerD.RealPosition + 5);
        }

        if(FOnChange) this->FOnChange(this);
}
//---------------------------------------------------------------------------
enum TVisualComponent { vcNone, vcMarkerA,vcMarkerB,vcMarkerC,vcMarkerD,vcLine };
TVisualComponent Active;
int LineId;
void __fastcall TLineChart::MouseMove(TShiftState Shift, int X, int Y)
{
        if(this->DontMoveLines)
                return;

        double _kx = 1;
        if(this->Seamples > 0)
                _kx = this->Width / (double)this->Seamples;
        switch(Active)
        {
                case vcMarkerA:
                        {
                                if(X < 0)
                                {
                                        this->MarkerA.RealPosition = 0;
                                        this->MarkerA.SeamplesPosition = (int)(this->MarkerA.RealPosition / _kx);
                                        this->Invalidate();
                                        break;
                                }
                                if(X > this->Width)
                                {
                                        this->MarkerA.RealPosition = this->Width;
                                        this->MarkerA.SeamplesPosition = (int)(this->MarkerA.RealPosition / _kx);
                                        this->Invalidate();
                                        break;
                                }
                                this->MarkerA.RealPosition = X;
                                this->MarkerA.SeamplesPosition = (int)(this->MarkerA.RealPosition / _kx);
                                this->Invalidate();
                        }
                        break;
                case vcMarkerB:
                {
                                if(X < 0)
                                {
                                        this->MarkerB.RealPosition = 0;
                                        this->MarkerB.SeamplesPosition = (int)(this->MarkerB.RealPosition / _kx);
                                        this->Invalidate();
                                        break;
                                }
                                if(X > this->Width)
                                {
                                        this->MarkerB.RealPosition = this->Width;
                                        this->MarkerB.SeamplesPosition = (int)(this->MarkerB.RealPosition / _kx);
                                        this->Invalidate();
                                        break;
                                }
                                this->MarkerB.RealPosition = X;
                                this->MarkerB.SeamplesPosition = (int)(this->MarkerB.RealPosition / _kx);
                                this->Invalidate();
                        }
                        break;
                case vcMarkerC:
                {
                                if(Y < 0)
                                {
                                        this->MarkerC.RealPosition = 0;
                                        this->Invalidate();
                                        break;
                                }
                                if(Y > this->Height)
                                {
                                        this->MarkerC.RealPosition = this->Height;
                                        this->Invalidate();
                                        break;
                                }
                                this->MarkerC.RealPosition = Y;
                                this->Invalidate();
                        } break;
                case vcMarkerD:
                {
                                if(Y < 0)
                                {
                                        this->MarkerD.RealPosition = 0;
                                        this->Invalidate();
                                        break;
                                }
                                if(Y > this->Height)
                                {
                                        this->MarkerD.RealPosition = this->Height;
                                        this->Invalidate();
                                        break;
                                }
                                this->MarkerD.RealPosition = Y;
                                this->Invalidate();
                }  break;
                case vcLine :
                {
                        this->Lines[LineId]->Offest = (this->Height / 2) - Y;
                        this->Invalidate();
                } break;
        }

        // Mark mouse
        // Marker A,B
        if((Y < 10 &&
        this->MarkerA.RealPosition - 5 < X &&
        this->MarkerA.RealPosition + 5 > X) ||
        (Y > this->Height - 10  &&
        this->MarkerB.RealPosition - 5 < X &&
        this->MarkerB.RealPosition + 5 > X))
        {
            Screen->Cursor = crSizeWE;
            return;
        }
        // Marker C,D
        if((X < 10 &&
        this->MarkerC.RealPosition - 5 < Y &&
        this->MarkerC.RealPosition + 5 > Y) ||
        (X > this->Width - 10 &&
        this->MarkerD.RealPosition - 5 < Y &&
        this->MarkerD.RealPosition + 5 > Y))
        {
           Screen->Cursor = crSizeNS;
           return;
        }

        // Lines
        for(int i=0; i < this->Lines.size(); i++)
        {
                if(((this->Height / 2) - this->Lines[i]->Offest + 5) > Y &&
                   ((this->Height / 2) - this->Lines[i]->Offest - 5) < Y)
                {
                   Screen->Cursor = crSizeNS;
                   return;
                }
        }

        Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TLineChart::MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(this->DontMoveLines)
                return;

        if(Button != mbLeft)
                return;

        // Marker A
        if(Y < 10 &&
        this->MarkerA.RealPosition - 5 < X &&
        this->MarkerA.RealPosition + 5 > X)
        {
                Active = vcMarkerA;
                Screen->Cursor = crSizeWE;
                return;
        };

        // Marker B
        if(Y > this->Height - 10  &&
        this->MarkerB.RealPosition - 5 < X &&
        this->MarkerB.RealPosition + 5 > X)
        {
                Active = vcMarkerB;
                Screen->Cursor = crSizeWE;
                return;
        };

        // Marker C
        if(X < 10 &&
        this->MarkerC.RealPosition - 5 < Y &&
        this->MarkerC.RealPosition + 5 > Y)
        {
                Active = vcMarkerC;
                Screen->Cursor = crSizeNS;
                return;
        };

        // Marker D
        if(X > this->Width - 10 &&
        this->MarkerD.RealPosition - 5 < Y &&
        this->MarkerD.RealPosition + 5 > Y)
        {
                Active = vcMarkerD;
                Screen->Cursor = crSizeNS;
                return;
        };

        // Lines
        for(int i=0; i < this->Lines.size(); i++)
        {
                if(((this->Height / 2) - this->Lines[i]->Offest + 5) > Y &&
                   ((this->Height / 2) - this->Lines[i]->Offest - 5) < Y)
                {
                   Active = vcLine;
                   Screen->Cursor = crSizeNS;
                   LineId = i;
                   return;
                }
        }

        Active = vcNone;
        Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TLineChart::MouseUp(TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(this->DontMoveLines)
                return;
                
        Screen->Cursor = crDefault;
        if(Active == vcNone)
        {
                this->Invalidate();
                return;
        }

        Active = vcNone;
        this->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TLineChart::Resize()
{
}
//---------------------------------------------------------------------------
