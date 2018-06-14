#include "Fraction.h"
#include<iostream>

Fraction::Fraction(){
	num = 1;
	denom = -1;
}

Fraction::Fraction(int num1, int denom1){
	num = num1;
	denom = denom1;
}

Fraction Fraction::operator+(const Fraction& fraction){
	num = num + fraction.num;
	denom = denom + fraction.denom;
	return *this;
}

Fraction& Fraction::operator=(const Fraction& fraction){
	num = fraction.num;
	denom = fraction.denom;
	return *this;
}

bool Fraction::operator>(const Fraction& fraction){
	if(double(num)/double(denom) > double(fraction.num)/double(fraction.denom)){
		return true;
	}
	else return false;
}

bool Fraction::operator<(const Fraction& fraction){
	if(double(num)/double(denom) < double(fraction.num)/double(fraction.denom)) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction){
	os << fraction.num << '/' << fraction.denom << ' ';
	return os;
}
