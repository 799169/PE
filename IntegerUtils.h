#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "ArrayUtils.h"

using namespace std;

namespace IntegerUtils {

	const int MAXTEN = 18;
	long long ten[MAXTEN + 1];
	void generateTen() {
		ten[0] = 1LL;
		for (int i = 1; i <= MAXTEN; ++i) {
			ten[i] = ten[i - 1] * 10LL;
		}
	}

	const int MAXFACTORIAL = 20;
	long long factorial[MAXFACTORIAL + 1];
	void generateFactorial() {
		factorial[0] = 1LL;
		for (int i = 1; i <= MAXFACTORIAL; ++i) {
			factorial[i] = factorial[i - 1] * 10;
		}
	}

	const int MAXTWO = 63;
	long long two[MAXTWO + 1];
	void generateTwo() {
		two[0] = 1LL;
		for (int i = 1; i <= MAXTWO; ++i) {
			two[i] = two[i - 1] * 10;
		}
	}

	const int MAXDIGIT = 9;
	bool pandigital[MAXDIGIT];

	bool isPandigital(int n) {
		int d;
		fill(pandigital, MAXDIGIT, false);
		while (n > 0) {
			d = n % 10;
			if (d == 0 or pandigital[d]) {
				return false;
			}
			pandigital[d] = true;
		}
		for (int i = 0; i < MAXDIGIT; ++i) {
			if (!pandigital[i]) {
				return false;
			}
		}
		return true;
	}

	auto APsum(auto a, auto d, auto n) {
		return n * (2LL * a + n * d - d) / 2;
	}

	auto gcd(auto a, auto b) {
		if (a < 0 or b < 0) {
			cerr << "GCDError" << endl;
			exit(0);
		}
		auto c = a;
		while (b > 0) {
			c = a;
			a = b;
			b = c % b;
		}
		return a;
	}

	auto reverse(auto n) {
		if (n < 0) {
			cerr << "ReverseError" << endl;
		}
		auto r = n;
		r = 0;
		while (n > 0) {
			r = (r * 10) + (n % 10);
			n /= 10;
		}
		return r;
	}

	int length(auto n) {
		if (n < 0) {
			cerr << "LengthError" << endl;
		}
		if (n == 0) {
			return 1;
		}
		int r = 0;
		while (n > 0) {
			++r;
			n /= 10;
		}
		return r;
	}

	auto concatenate(int x, int y) {
		if (x < 0 or y < 0) {
			cerr << "ConcatenateError" << endl;
		}
		return x * ten[length(y)] + y;
	}

	int sumOfDigits(int n) {
		if (n < 0) {
			cerr << "SumOfDigitsError" << endl;
		}
		int s = 0;
		while (n > 0) {
			s += (n % 10);
			n /= 10;
		}
		return s;
	}

	template <class T> T sum(const T &t) {
		return t;
	}

	template <class T, class... U> T sum(const T &t, const U... u) {
		return t + sum(u...);
	}

	template <class T> T product(const T &t) {
		return t;
	}

	template <class T, class... U> T product(const T &t, const U... u) {
		return t * product(u...);
	}
}

using namespace IntegerUtils;
