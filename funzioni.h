#include <string>
#include <vector>
#include "class.h"
#include "TAxis.h"
#include "TApplication.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"


using namespace std;

void Control(int );
void LoadData(string, vector<double> &);
void LoadGraph(TGraph *, vector<Point*>, int );
void SetGraph(TGraph *);
void GetMin(double &, double &,const TGraph *);
void PrintStat(double, double, vector<double>);

