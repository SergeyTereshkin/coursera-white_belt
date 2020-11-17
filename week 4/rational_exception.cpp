#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <stdexcept>
#include <sstream>
using namespace std;

void CheckIfDenomIsZero(int denominator) {
    stringstream ss;
    ss << denominator;
    string denom = ss.str();
    if (denominator == 0) {
        throw invalid_argument(denom);
    }
}


void CheckIfDivisorIsZero(int divisor) {
    stringstream ss;
    ss << divisor;
    string div = ss.str();
    if (divisor == 0) {
        throw domain_error(div);
    }
}


class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        CheckIfDenomIsZero(denominator);
        int first_number = abs(numerator);
        int second_number = abs(denominator);
        while (first_number > 0 && second_number > 0) {
            if (first_number > second_number) {
                first_number = first_number % second_number;
            }
            else {
                second_number = second_number % first_number;
            }
        }
        int divisor = first_number + second_number;
        if (numerator < 0 && denominator < 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        else if (numerator > 0 && denominator < 0) {
            numerator = -numerator;
            denominator = abs(denominator);
        }
        if (numerator == 0) {
            p = 0;
            q = 1;
        }
        else {
            p = numerator / divisor;
            q = denominator / divisor;
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator()};
}


Rational operator-(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator()};
}


bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}


Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}


Rational operator/(const Rational& lhs, const Rational& rhs) {
    CheckIfDivisorIsZero(lhs.Denominator() * rhs.Numerator());
    return {lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()};
}


ostream& operator<<(ostream& stream, const Rational& fraction) {
    stream << fraction.Numerator() << '/' << fraction.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& fraction) {
    if (stream.good())
    {
        int num=0, denom=1;
        stream >> num;
        stream.ignore(1);
        stream >> denom;
        fraction = Rational(num, denom);
    }
    else {
        stream.setstate(ios_base::failbit);
    }
    return stream;
}



bool operator<(const Rational& lhs, const Rational& rhs) {
    int res = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    return res < 0;
}

