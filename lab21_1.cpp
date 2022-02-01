#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1,Rect R2){
	double L;
	double W;
	double sum;
	if(R2.x > R1.x){
		L = (R1.x+R1.w)-R2.x;
	}
	if(R2.x < R1.x){
		L = (R2.x+R2.w)-R1.x;
	}
	if(R1.y < R2.y){
		W = R1.y-(R2.y-R2.h);
	}
	if(R2.y < R1.y){
		W = R2.y-(R1.y-R1.h);
	}
	sum = L*W;
	if(sum < 0) sum = 0;
	if(sum > (R1.x+R1.w)*(R1.y+R1.h) || sum >(R2.x+R2.w)*(R2.y+R2.h)){
		if(sum > (R1.x+R1.w)*(R1.y+R1.h)){
			sum = (R1.x+R1.w)*(R1.y+R1.h);
		}else{
			sum = (R2.x+R2.w)*(R2.y+R2.h);
		}
	}
	return sum;
}