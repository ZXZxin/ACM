//题目链接：http://codeforces.com/gym/101522/problem/H
//题目大意：就是要你随便输出两个圆的公共部分的点
//解题思路：直接输出两个圆的圆心的连线的与两圆交点的中点，注意要判断没有两个交点的情况特判

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int maxn = 1000 + 10;

int main() {
	double x1, x2, y1, y2, r1, r2;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2) != EOF) {
		double dist = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if(dist < r1){
            cout<<x2<<" "<<y2<<endl;
		}
		else if(dist < r2){
            cout<<x1<<" "<<y1<<endl;
		}
		else {
            double d1 = x1 + (dist - r2)*(x2 - x1)/dist;
            double d2 = x2 - (dist - r1)*(x2 - x1)/dist;
            double k = (y1 - y2)/(x1 - x2);
            double b = y1 - k*x1;
            double yd1 = d1*k + b;
            double yd2 = d2*k + b;
            cout<<(d1+d2)/2<<" "<<(yd1+yd2)/2<<endl;
		}
	}
	return 0;
}
