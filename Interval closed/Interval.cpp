#include <iostream>
#include "Interval.h"
#include<assert.h>
using namespace Math;
using namespace std;
Math::Interval::Interval(double min, double max)
{
    assert(min <= max);
    this->Min = min;
    this->Max = max;
}
Math::Interval::Interval()
{
    this->Max = 0;
    this->Min = 0; 
}

Math::Interval& Math::Interval::operator|(const Interval& R2) const
{
    if (this == &R2) { 
        return *(new Interval(*this)); 
    }
   if (this->Appartien(R2))return *(new Interval(*this)); 
   if (R2.Appartien(*this))return *(new Interval(R2)); 
   if (this->Max<R2.Min || this->Min>R2.Max)return *(new Interval);
   Interval* New = new Interval;
   if (this->Max < R2.Max) 
   {
       New->Max = R2.Max;
   }
   else 
   {
       New->Max = this->Max;
   }
   if (this->Min > R2.Min)
   {
       New->Min = R2.Min;
   }
   else {
       New->Min = this->Min;
   }
   return  *New;
}

Interval& Math::Interval::operator&(const Interval& R2) const
{
    if (this->Max<R2.Min || this->Min>R2.Max)return *(new Interval);
    if (this->Appartien(R2.Min) && this->Appartien(R2.Max))return *(new Interval(R2));
    if (R2.Appartien(this->Min) && R2.Appartien(this->Max))return *(new Interval(*this));
    Interval* New = new Interval;
    if (this->Max < R2.Max)
    {
        New->Max = this->Max;
    }
    else if (this->Max > R2.Max)
    {
        New->Max = R2.Max;
    }
    else {
        New->Max = this->Max;
    }
    if (this->Min > R2.Min)
    {
        New->Min = this->Min;
    }
    else{
        New->Min = R2.Min;
    }
    return  *New;
}

void Math::Interval::print() const
{
    if (this->isempty())
    {
        cout << "interval Vide ";
    }
    cout << "[" << this->Min << " , " << this->Max <<"]"<< endl;
}

double Math::Interval::Maximum()const
{
    return this->Max;
}

double Math::Interval::Minimum()const
{
    return this->Min;
}

bool Math::Interval::Appartien(double num)const
{

    if (this->Min > num)return false;
    if (this->Max < num)return false;
    return true;
}

bool Math::Interval::Appartien(const Interval& R2) const
{
    if (this->Appartien(R2.Min) && this->Appartien(R2.Max))return true;
    return false;
}
bool Math::Interval::operator[](const Interval& num) const
{
    return this->Appartien(num);
}

bool Math::Interval::operator[](double num) const
{
    return this->Appartien(num);
}

bool Math::Interval::isempty() const
{
    if (this->Max == this->Min && this->Max==0)return true;
    return false;
}

