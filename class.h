#ifndef _point_
#define _point_

#include <vector>

class Point {

	public:

	Point();
	Point(double q);

	void EvalK(const std::vector<double> &Qi); 
	double GetQ() const {return m_q;};
	double GetSq() const {return m_Sq;};
	double GetK(int pos) const {return m_k[pos];}; 
	void EvalSq(const std::vector<double> &Qi);

	~Point();

	private:

	double m_Sq;
	double m_q;
	std::vector<double> m_k;
};

#endif

