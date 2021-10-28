#include"Interval.h"
#include<iostream>
using namespace std;
using namespace Math;
int main() 
{
	Interval Ne(13,45);
	Interval NZ(14 ,15);
	Interval NW = Ne & NZ;
	NW.print();
	return 1;
}