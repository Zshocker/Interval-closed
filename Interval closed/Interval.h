#pragma once
namespace Math {
	class Interval
	{
	private:
		double Min;
		double Max;
	public:
		Interval();
		Interval(double min, double max);
		double Maximum()const;
		double Minimum()const;
		bool Appartien(double num)const;
		bool Appartien(const Interval& num)const;
		bool isempty()const;
		//supposant que [] fait le meme traitement que Appartien
		bool operator[](const Interval& num)const;
		bool operator[](double num)const;
		Interval& operator|(const Interval& R2)const;
		Interval& operator&(const Interval& R2)const;
		void print()const;
	};
}