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
#include <vector>


using namespace std;
using namespace chrono;


namespace IntegerUtils {

	int lengthInt(auto n) {
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
}


struct BigInteger {

	static const int N = 1000;
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
		return IntegerUtils::lengthInt(a[i]) + D * (N - i - 1);
	}

};


namespace FibonacciUtils {

	const int MAXF = 100;
	BigInteger cache[MAXF] =  {
		BigInteger(0), BigInteger(1), BigInteger(1)
	};

	void buildCache() {
		for (int i = 2; i < MAXF; ++i) {
			cache[i].clear();
			cache[i].add(cache[i - 1]);
			cache[i].add(cache[i - 2]);
		}
	}

	auto fib(int n) {
		if (n < MAXF) {
			return cache[n];
		}
		BigInteger b1, b2;
		if (n % 2 == 0) {
			auto f1 = fib(n / 2);
			auto f2 = fib(n / 2 + 1);
			auto f3 = fib(n / 2 - 1);
			f2.add(f3);
			f1.multiply(f2, f3);
			return f3;
		} else {
			auto f1 = fib((n + 1) / 2);
			auto f2 = fib((n - 1) / 2);
			f1.multiply(f1, b1);
			f2.multiply(f2, b2);
			b1.add(b2);
			return b1;
		}
	}

}



struct Problem25 {

	auto solve() {
		const int D = 1000;
		auto SQRT5 = sqrt(5.0L);
		auto PHI = (1 + SQRT5) / 2;
		auto PSI = (1 - SQRT5) / 2;
		int n = (D - 1 + log10(5) / 2) / log10(PHI);
		FibonacciUtils::buildCache();
		while (FibonacciUtils::fib(n).numOfDigits() < D) {
			++n;
		}
		return n;
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
    Answer:       4782
 Time taken:   1.27307s
***********************/
