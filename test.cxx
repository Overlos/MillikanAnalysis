#include "funzioni.h"
#include "class.h"
#include <string>
#include <iostream>
#include "TAxis.h"
#include "TApplication.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;

int main(int argc, char** argv){

Control(argc);

TApplication app("app",0,0); //loop che mi permette di vedere i grafici

string filename = argv[1];
double q_start = atof(argv[2]);
double bin = atof(argv[3]);
int nbin = atoi(argv[4]);

vector<double> Qi;
vector<Point*> Points;

LoadData(filename, Qi);

for(int i=0; i<nbin; i++){
	Points.push_back(new Point(q_start));
	q_start+=bin;
	Points[i]->EvalK(Qi);
	Points[i]->EvalSq(Qi);
	}

TGraph * g = new TGraph() ; // riempio il vettore con punti
TCanvas *myGraph = new TCanvas("MyGraph","Grafico");

LoadGraph(g,Points,nbin);
SetGraph(g);

double xmin, ymin;

GetMin(xmin, ymin, g);
PrintStat(xmin, ymin, Qi);

g->Draw("AC");
app.Run();

return 0;
}

