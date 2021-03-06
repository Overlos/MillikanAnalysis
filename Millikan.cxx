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
string filename2 = argv[2];
double q_start = atof(argv[3]);
double bin = atof(argv[4]);
int nbin = atoi(argv[5]);

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
int n=0;

n=GetMin(xmin, ymin, g);

vector<double> SQi;
double tmp=0;
LoadData(filename2, SQi);

EvalSigma(Points,Qi,SQi,tmp,n);


/*
for(int i=0; i<Qi.size()-1;i++){
	tmp+=pow(SQi[i]/((Qi.size()-1)*Points[n]->GetK(i)),2);
	}

tmp=sqrt(tmp);
*/

PrintStat(xmin, ymin, Qi, tmp);

g->Draw("AC");
app.Run();

return 0;
}

