#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect &R1,Rect &R2){
	Rect *r1 = &R1;
	Rect *r2 = &R2;
	double L;
	double W;
	double sum;
	if(r2 -> x > r1 -> x){
		L = (r1->x+r1->w)-r2->x;
	}
	if(r2->x < r1->x){
		L = (r2->x+r2->w)-r1->x;
	}
	if(r1->y < r2->y){
		W = r1->y-(r2->y-r2->h);
	}
	if(r2->y < r1->y){
		W = r2->y-(r1->y-r1->h);
	}
	sum = L*W;
	if(sum < 0) sum = 0;
	if(sum > (r1->x+r1->w)*(r1->y+r1->h) || sum >(r2->x+r2->w)*(r2->y+r2->h)){
		if(sum > (r1->x+r1->w)*(r1->y+r1->h)){
			sum = (r1->x+r1->w)*(r1->y+r1->h);
		}else{
			sum = (r2->x+r2->w)*(r2->y+r2->h);
		}
	}
	return sum;
}

