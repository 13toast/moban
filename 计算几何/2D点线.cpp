#include <bits/stdc++.h>
using namespace std;


const double INF = 1e20;
const double eps = 1e-8;
const double PI = 3.14159265358979323846;

int sgn(double _) {
	if (fabs(_) < eps) return 0;
	if (_ < 0) return -1;
	return 1;
}

struct Point {
	double x, y;
	Point(double _, double __) { x = _; y = __; }	

	bool operator == (Point p) const { return (sgn(x-p.x) == 0) && (sgn(y-y.x) == 0); }
	bool operator < (Point p) const { return (sgn(x-p.x) == 0) ? sgn(y-p.y) < 0 : x < p.x; }
	Point operator + (const Point &p) const { return Point(x+p.x, y+p.y); }
	Point operator - (const Point &p) const { return Point(x-p.x, y-p.y); }
	Point operator * (const double &k) const { return Point(x*k, y*k); }
	Point operator / (const double &k) const { return Point(x/k, y/k); }
	double operator * (Point &p) const { return x * p.x + y * p.y; }
	double operator ^ (Point &p) const { return x * p.y - y * p.x; }
	
	double length() { return hypot(x,y); }
	double lensq() { return x * x + y * y; }
	double dis_point(Point p) { return hypot(x-p.x,y-p.y);}
};
struct Line {
	
};

//两向量夹角
double rad(Point a, Point b) { return fabs(atan2(fabs(a^b), a*b)); }
double rad_to_deg(double r) { return 180.0 * r / PI; }


int main() {
	
}