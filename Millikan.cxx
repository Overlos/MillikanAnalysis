#include <iostream>
#include <fstream>
#include "funzioni.h"
#include "TAxis.h"
#include "TApplication.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv){

Control(argc);

double echarge=1.60217e-19;

TApplication app("app",0,0); //loop che mi permette di vedere i grafici

string filename = argv[1];
int nbin = atoi(argv[4]);
double e = atof(argv[2]);
double bin = atof(argv[3]);
ifstream in(filename);
vector<double> Qi;

if(!in){

	cout<< "Achtung! File not found, exiting" << endl;
	exit(1);

	}else{

	while(!in.eof()){
		double value = 0;
		in >> value;
		Qi.push_back(value);
		}
	}

vector<double> q;

for(int i=0; i<nbin; i++){
	q.push_back(e);
	e+=bin; 
	}

vector<double> k[nbin];

double param, fractpart, intpart;

for(int a=0; a<nbin ; a++){
		for(int i=0; i<Qi.size()-1; i++){
		param=((Qi[i]/q[a])+0.5);
		fractpart=modf(param, &intpart);
		k[a].push_back(intpart);
	}
}

vector<double> S_q[nbin];

for(int a=0; a<nbin; a++){
	for(int i=0; i<Qi.size()-1; i++){
		S_q[a].push_back(pow(((Qi[i]/k[a].at(i))-q[a]),2));
	}
}

vector<double> S_qfinal;

double sum=0;

for(int a=0; a<nbin; a++){
	for(int i=0; i <Qi.size()-1; i++){
		sum+=S_q[a].at(i);
		}
		S_qfinal.push_back(sum);
		sum=0;
	}

TGraph * g = new TGraph() ;
  
// riempio il vettore con punti

for(int a=0; a<nbin; a++){  
   double x = q[a];
   double y = S_qfinal[a];		      
    g->SetPoint(a, x , y);
  }

int n = g->GetN();
double* x = g->GetX();
double* y = g->GetY();
int locmin = TMath::LocMin(n,y);
double xmin = x[locmin];
double ymin = y[locmin];

double distance = abs(xmin-echarge);
double percentage = (distance*100)/echarge;
double stdev = sqrt(ymin/(Qi.size()*(Qi.size()-1)));
double sigma = distance/stdev;

cout <<"The best value for the electron's charge is  " << xmin << endl;
cout <<"In that point S_q is equal to " << ymin << endl;
cout <<"The deviation from the true value is " << distance << endl;
cout <<"And the percentual deviation is  "<< percentage << "%" << endl;
cout <<"The stdev is " << stdev << endl;
cout <<"And the deviation in terms of stdev is " << sigma << endl;

TCanvas *myGraph = new TCanvas("MyGraph","Grafico");
g->SetTitle("Trend of  S(q)");
g->GetXaxis()->SetTitle("q [C]");
g->GetYaxis()->SetTitle("S(q) [C^2]");

g->Draw("AC");

app.Run();

return 0;
}

