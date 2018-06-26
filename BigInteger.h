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
#include "IntegerUtils.h"
using namespace std;


int counter = 0;

struct BigInteger {

	static const int N = 100;
	long long a[N];

	const long long B = 10000LL;
	const int D = 4;

	void clear() {
		for (int i = 0; i < N; ++i) {
			a[i] = 0LL;
		}
	}

	BigInteger()  {
		clear();
	}

	BigInteger(auto x) {
		clear();
		int i = N - 1;
		while (x > 0) {
			a[i] = x % B;
			x /= B;
			--i;
		}
	}

	void print() {
		int i = 0;
		while (i < N && a[i] == 0) {
			++i;
		}
		while (i < N) {
			cout << setfill('0') << setw(D) << a[i];
			++i;
		}
		cout << endl;
	}

	void add(BigInteger &b) {
		auto c = 0LL;
		for (int i = N - 1; i >= 0; --i) {
			a[i] += b.a[i] + c;
			c = 0;
			if (a[i] >= B) {
				a[i] -= B;
				c = 1;
			}
		}
	}

	void multiply(int x) {
		auto c = 0LL;
		for (int i = N - 1; i >= 0; --i) {
			auto d = a[i] * x + c;
			a[i] = d % B;
			c = d / B;
		}
	}

	void normalize(BigInteger &b) {
		auto c = 0LL;
		for (int i = N - 1; i >= 0; --i) {
			b.a[i] += c;
			c = b.a[i] / B;
			b.a[i] %= B;
		}
	}

	void multiply(BigInteger &b,  BigInteger &r) {
		auto c = 0LL;
		r.clear();
		for (int i = N - 1; i >= 0; --i) {
			for (int j = N - 1; j >= 0; --j) {
				r.a[i - N + 1 + j] += a[i] * b.a[j];
			}
		}
		normalize(r);
	}

	int numOfDigits() {
		int i = 0;
		while (i < N && a[i] == 0) {
			++i;
		}
		return length(a[i]) + D * (N - i - 1);
	}

};

