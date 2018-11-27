#include "class.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

Point::Point(){
	m_q=0;
	m_Sq=0;
}

Point::Point(double qi ){
	m_q=qi;
	m_Sq=0;
}

Point::~Point(){

}

void Point::EvalK(const vector<double> &Qi){
	
	double param, fractpart, intpart;

	for(int i=0; i<Qi.size()-1; i++){
		param=((Qi[i]/GetQ())+0.5);
		fractpart=modf(param, &intpart);
		m_k.push_back(intpart);
		}
		m_k.shrink_to_fit();
}

void Point::EvalSq(const std::vector<double> &Qi){

	for(int i=0; i<Qi.size()-1; i++){
		m_Sq+=pow((Qi[i]/GetK(i)-GetQ()),2);
		}
}

