#include <iostream>


struct IntegerUtils {

	static auto APsum(auto a, auto d, auto n) {
		return n * (2 * a + n * d - d) / 2;
	}

	static auto gcd(auto a, auto b) {
		auto c = a;
		while (b > 0) {
			c = a;
			a = b;
			b = c % b;
		}
		return a;
	}

};


struct Fraction {

	auto a, b;

	Fraction(auto x, auto y) : a(x), b(y)  {}

	void multiply(Fraction &f) {
		a *= f.a;
		b *= f.b;
		g = IntegerUtils::gcd(a, b);
		a /= g;
		b /= g;
	}

};

int main() {

	return 0;
}