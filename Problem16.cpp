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

namespace IntegerUtils {

	int sumOfDigits(auto n) {
		int s = 0;
		while (n > 0) {
			s += (n % 10);
			n /= 10;
		}
		return s;
	}

}

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
		for (int i = 0; i < N; ++i) {
			cout << setfill('0') << setw(D) << a[i];

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

};


struct Problem16 {

	auto solve() {
		const int B = 2, N = 1000;
		BigInteger b(1);
		for (int i = 0; i < N; ++i) {
			b.multiply(B);
		}
		int s = 0;
		for (int i = 0; i < BigInteger::N; ++i) {
			s += IntegerUtils::sumOfDigits(b.a[i]);
		}
		return s;
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
    Answer:       1366
 Time taken:   0.00300s
 ************************/
