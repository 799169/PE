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
#include "BigInteger.h"

using namespace std;
using namespace chrono;


namespace FibonacciUtils {

	// const int MAXF = 10;
	// long long cache[MAXF] =  {
	// 	0, 1, 1, 2, 3, 5, 8, 13, 21, 34
	// };

	// auto fibInt(int n) {
	// 	if (n < MAXF) {
	// 		return cache[n];
	// 	}
	// 	if (n % 2 == 0) {
	// 		auto f1 = fibInt(n / 2);
	// 		auto f2 = fibInt(n / 2 + 1);
	// 		auto f3 = fibInt(n / 2 - 1);
	// 		return f1 * (f2 + f3);
	// 	} else {
	// 		auto f1 = fibInt((n + 1) / 2);
	// 		auto f2 = fibInt((n - 1) / 2);
	// 		return f1 * f1 + f2 * f2;
	// 	}
	// }

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

using namespace FibonacciUtils;

