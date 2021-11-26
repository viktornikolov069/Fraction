#ifndef  FRACTION_H
#define FRACTION_H

#include <ostream>
#include <cmath>
#include <string>

class Fraction {
public:
	Fraction(int num, int denom) {
		int gcd = greatestCommonDivisor(num, denom);
		_numerator = num / gcd;
		_denominator = denom / gcd;
	}

	int getNumerator() const {
		return _numerator;
	}

	int getDenominator() const {
		return _denominator;
	}

	bool operator<(const Fraction& other) const {
		return _numerator * other._denominator < _denominator* other._numerator;
	}

	bool operator>(const Fraction other) const {
		return *this < other;
	}

	Fraction operator*(const int multiplier) const {
		return Fraction(_numerator * multiplier, _denominator);
	}

	Fraction operator*(const Fraction& other) const {
		return Fraction(_numerator * other._numerator, _denominator * other._denominator);
	}

	Fraction operator/(const Fraction& other) const {
		return Fraction(_numerator * other._denominator, _denominator * other._numerator);
	}

private:
	int _numerator = 0;
	int _denominator = 0;

	static int greatestCommonDivisor(int num, int denom) {
		int remainder = 0;

		while (num % denom > 0) { // Euclidian algorithm
			remainder = num % denom;
			num = denom;
			denom = remainder;
		}
		return denom;
	}
};

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
	out << frac.getNumerator();
	if (frac.getDenominator() != 1) {
		out << '/' << frac.getDenominator();
	}
	return out;
}

#endif // ! FRACTION_H
