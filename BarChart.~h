//---------------------------------------------------------------------------

#ifndef BarChartH
#define BarChartH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <vector>
//---------------------------------------------------------------------------
// Related class and structures
typedef struct TBarItem
{
        double Data;
        TColor Color;
        double Gain;
} BarItem;
//---------------------------------------------------------------------------
using namespace std;
class PACKAGE TBarChart : public TGraphicControl
{
private:
protected:
        void __fastcall Paint();
public:
        vector<BarItem*> Lines;
        __fastcall TBarChart(TComponent* Owner);
__published:
};
//---------------------------------------------------------------------------
#endif
