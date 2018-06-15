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
#include <sstream>
#include <string>
#include <tuple>


using namespace std;
using namespace chrono;


struct Problem14 {

	const int N = 1e6;
	static const int X = 15;
	static const long long B = (1LL << X);
	int table[B][3], d[B];

	long long a, b, c, x, y, t, g, h;

	auto solve() {
		d[1] = 1;
		for (int i = 2; i < B; ++i) {
			collatz(i);
		}
		for (int i = 0; i < B; ++i) {
			build(B, i);
			table[i][0] = a;
			table[i][1] = b;
			table[i][2] = c;
		}
		int mxn = 13, mxc = 10;
		for (int i = N / 2; i < N; ++i) {
			g = collatzX(i);
			if (g > mxc) {
				mxc = g;
				mxn = i;
			}
		}
		return mxn;
	}

	int collatz(long long i) {
		if (i < B && d[i] > 0) {
			return d[i];
		}
		if (i & 1) {
			t = collatz((3 * i + 1) / 2) + 2;
		} else {
			t = collatz(i / 2) + 1;
		}
		return (i < B) ? (d[i] = t) : t;
	}

	int collatzX(long long n) {
		if (n < B) {
			return d[n];
		}
		x = n / B;
		y = n % B;
		return collatzX(table[y][0] * x + table[y][1]) + table[y][2];
	}


	void build(long long x, long long y) {
		int p = x & 1, q = y & 1;
		if (p == 1) {
			a = x;
			b = y;
			c = 0;
		} else if (q == 0) {
			build(x / 2, y / 2);
			++c;
		} else {
			build((3 * x + 1) / 2, (3 * y + 1) / 2);
			c += 2;
		}
	}

} solver;


int main() {
	freopen("output.txt", "w+", stdout);
	auto start = high_resolution_clock::now();
	auto ans = solver.solve();
	auto end = high_resolution_clock::now();
	duration <double> diff = end - start;
	cout << setw(12) << " Answer: " << setw(10) << ans;
	cout << "\n Time taken: " << setw(9) << fixed;
	cout << setprecision(5) << diff.count() << "s\n\n";
	return 0;
}

/***********************
    Answer:     837799
 Time taken:   0.02500s
************************/
