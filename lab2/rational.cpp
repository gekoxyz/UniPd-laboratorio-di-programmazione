#include <iostream>
using namespace std;

class rational {
  int numerator;
  int denominator;

  public:
  rational() {
    numerator = 0;
    denominator = 1;
  }

  rational(int n) {
    numerator = n;
    denominator = 1;
  }

  rational(int n, int d) {
    numerator = n;
    if (d == 0) throw Invalid();
    denominator = d;
  }
  
  void operator=(const rational& r) {
    this->numerator = r.numerator;
    this->denominator = r.denominator;
  } 

  rational operator+(const rational& r) {
    // a/b + c/d = (a*d + c*b) / b*d 
    int numerator = this->numerator * r.denominator + this->denominator * r.numerator;
    int denominator =  this->denominator * r.denominator;
    return rational(numerator, denominator);
  }

  rational operator-(const rational& r) {
    // a/b + c/d = (a*d - c*b) / b*d 
    int numerator = this->numerator * r.denominator - this->denominator * r.numerator;
    int denominator =  this->denominator * r.denominator;
    return rational(numerator, denominator);
  }
  
  rational operator*(const rational& r) {
    // a/b * c/d = a*c / b*d
    int numerator = this->numerator * r.numerator;
    int denominator = this->denominator * r.denominator;
    return rational(numerator, denominator);
  }

  rational operator/(const rational& r) {
    // (a/b) / (c/d) = a/b * d/c
    return rational(this->numerator, this->denominator) * rational(r.denominator, r.numerator);
  }

  bool operator==(const rational &r) {
    double num1 = fraction_to_double(rational(this->numerator, this->denominator));
    double num2 = fraction_to_double(r);
    return num1 == num2;
  }

  bool operator<(const rational& r) {
    double num1 = fraction_to_double(rational(this->numerator, this->denominator));
    double num2 = fraction_to_double(r);
    return num1 < num2;
  }

  bool operator>(const rational& r) {
    double num1 = fraction_to_double(rational(this->numerator, this->denominator));
    double num2 = fraction_to_double(r);
    return num1 > num2;
  }

  int get_numerator() {
    return numerator;
  }

  int get_denominator() {
    return denominator;
  }

  private:

  double fraction_to_double(const rational& r) {
    return (double)r.numerator / (double)r.numerator;
  }
  class Invalid {};
};

int main() {
  rational n1(2,3); 
  rational n2(5,6);

  rational res = n1 + n2;
  // cout << res;

  res = n1 - n2;
  cout << res.get_numerator() << "/" << res.get_denominator() << "\n";

  res = n1 * n2;
  cout << res.get_numerator() << "/" << res.get_denominator() << "\n";
  
  res = n1 / n2;
  cout << res.get_numerator() << "/" << res.get_denominator() << "\n";

  cout << (rational(1, 2) == rational(2, 4)) << "\n";

  n1 = n2;
  return 0;
} 
