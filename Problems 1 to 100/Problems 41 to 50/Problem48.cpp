#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
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

#ifdef LOCAL
	#include "DebugUtils.h"
#endif

using namespace std;
using namespace chrono;

typedef long long IntL;
typedef vector <int> IntV;
typedef vector <bool> BoolV;


struct BigInteger {

	static const int N = 5;
	IntL a[N];

	const IntL B = 100000000LL;
	const int D = 8;

	void clear() {
		for (int i = 0; i < N; ++i) {
			a[i] = 0LL;
		}
	}

	BigInteger()  {
		clear();
	}

	BigInteger(IntL x) {
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

	void add(IntL x) {
		IntL c = 0;
		a[N - 1] += x;
		for (int i = N - 1; i >= 0; --i) {
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


};


struct Problem48 {

	auto solve() {
		IntL M = 1e10, ans;
		BigInteger x, s;
		for (int i = 1; i <= 1000; ++i) {
			x.clear();
			x.add(i);
			for (int j = 1; j < i; ++j) {
				x.multiply(i);
			}
			s.add(x);
		}
		ans = (s.a[BigInteger::N - 2] % 100) * 1e8 + s.a[BigInteger::N - 1];
		return ans;
	}

} solver;


int main() {
	freopen("output.txt", "w+", stdout);
	auto start = high_resolution_clock::now();
	auto ans = solver.solve();
	auto end = high_resolution_clock::now();
	durat
