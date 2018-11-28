#include "funzioni.h"
#include "class.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "TAxis.h"
#include "TApplication.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"

using namespace std;

void Control(int argc){
	
	if(argc!=6){
		cerr << "Error! You inserted " << argc << " argument(s) instead of the 6 required! Exiting!" << endl;
		exit(2);
		}
	}

void LoadData(string filename, vector<double> &Qi){

ifstream in(filename);

if(!in){

	cerr << "Achtung! File not found, exiting" <<endl;
	exit(3);

}else{

	while(!in.eof()){
		double value = 0;
		in >> value;
		Qi.push_back(value);
		}
	Qi.shrink_to_fit();
	}
}

void LoadGraph(TGraph *g, vector<Point*> Points, int nbin){ 

for(int a=0; a<nbin; a++){  
   double x = Points[a]->GetQ();
   double y = Points[a]->GetSq();		      
    g->SetPoint(a, x , y);
  }
}

void SetGraph(TGraph *g){

	g->SetTitle("Trend of  S(q)");
	g->GetXaxis()->SetTitle("q [C]");
	g->GetYaxis()->SetTitle("S(q) [C^2]");
}

int GetMin(double &xmin, double &ymin, const TGraph *g){

	int n = g->GetN();
	double* x = g->GetX();
	double* y = g->GetY();
	int locmin = TMath::LocMin(n,y);
	xmin = x[locmin];
	ymin = y[locmin];
	return locmin;
}

void PrintStat(double xmin, double ymin, vector<double> Qi, double tmp){
	
	double echarge=1.60217e-19;
	double distance = abs(xmin-echarge);
	double percentage = (distance*100)/echarge;
	double stdev = sqrt(ymin/((Qi.size()-1)*(Qi.size()-2)));
	double total = sqrt(pow(stdev,2)+pow(tmp,2));
	double sigma = distance/total;
	double stpercentage = (distance*100)/total;

	cout << "The best value for the electron's charge is " << xmin << endl;
	cout << "In that point S_q is equal to " << ymin << endl;
	cout << "The deviation from the true value is " << distance << endl;
	cout << "And the percentual deviation is  "<< percentage << "%" << endl;
	cout << "The stdev is " << stdev << endl;
	cout << "The sistematic error is " << tmp << endl;
	cout << "And the total error is " << total << endl;
	cout << "In term of total sigma, the deviation is " << sigma << endl;
	cout << "The percentual error is then " << stpercentage <<"%" << endl;

}

void EvalSigma(vector<Point*> Points, vector<double> Qi, vector<double> SQi, double &tmp, int n){

for(int i=0; i<Qi.size()-1;i++){
		tmp+=pow(SQi[i]/((Qi.size()-1)*Points[n]->GetK(i)),2);
		}

	tmp=sqrt(tmp);
}

