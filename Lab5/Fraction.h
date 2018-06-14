#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>

class Fraction{
	public:
		int num;
		int denom;
		Fraction();
		Fraction(int num1, int denom1);
		Fraction operator+(const Fraction& fraction);
		Fraction& operator=(const Fraction &fraction);
		bool operator>(const Fraction &fraction);
		bool operator<(const Fraction& fraction);
};

std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

#endif
