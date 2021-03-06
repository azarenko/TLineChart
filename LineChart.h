//---------------------------------------------------------------------------

#ifndef LineChartH
#define LineChartH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <vector>
//---------------------------------------------------------------------------
// Related class and structures
typedef struct TLineItem
{
        double* Data;
        int Width;
        TColor Color;
        int Offest;
        double Gain;
        bool MarkPoint;
        double Divide;
        double Scale;
} LineItem;
typedef struct TMarker
{
        TColor Color;
        int RealPosition;
        int SeamplesPosition;
} Marker;
//---------------------------------------------------------------------------
using namespace std;
class PACKAGE TLineChart : public TGraphicControl
{
private:
        TMouseEvent FOnMouseUp;
        TMouseEvent FOnMouseDown;
        TMouseMoveEvent FOnMouseMove;
        TNotifyEvent FOnChange;
        long _Seamples;
        long _VerticalOffset;
        bool _DontMoveLines;
        bool _DontShowMarkers;
protected:
        void __fastcall Paint();
        void __fastcall DYNAMIC Resize();
        void __fastcall DYNAMIC MouseMove(TShiftState Shift, int X, int Y);
        void __fastcall DYNAMIC MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall DYNAMIC MouseUp(TMouseButton Button, TShiftState Shift, int X, int Y);
public:
        Marker MarkerA;
        Marker MarkerB;
        Marker MarkerC;
        Marker MarkerD;
        vector<LineItem*> Lines;
        __fastcall TLineChart(TComponent* Owner);
__published:
        __property TMouseMoveEvent OnMouseMove = { read=FOnMouseMove, write=FOnMouseMove };
        __property TMouseEvent OnMouseUp = { read=FOnMouseUp, write=FOnMouseUp };
        __property TMouseEvent OnMouseDown = { read=FOnMouseDown, write=FOnMouseDown };
        __property TNotifyEvent OnChange = { read=FOnChange, write=FOnChange };
        __property long Seamples = { read=_Seamples, write=_Seamples };
        __property long VerticalOffset = { read=_VerticalOffset, write=_VerticalOffset };
        __property bool DontMoveLines = { read=_DontMoveLines, write=_DontMoveLines };
        __property bool DontShowMarkers = { read=_DontShowMarkers, write=_DontShowMarkers };
};
//---------------------------------------------------------------------------
#endif
