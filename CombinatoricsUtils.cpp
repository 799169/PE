#include <bits/stdc++.h>
using namespace std;

typedef istream_iterator <string> iis;
typedef stringstream tss;

#define tr(x...) { string _s = #x; replace(begin(_s), end(_s), ',', ' '); tss _ss(_s); iis _it(_ss); trx(_it, x); }

void trx(iis it) { cout << endl; }

template<typename T, typename... U> void trx(iis it, T a, U... u) {
	cout << *it << "=" << a << ' ';
	trx(++it, u...);
}

namespace CombinatoricsUtils {

	// auto nCk(int n, int k) {
	// 	int p;
	// 	map <int, int> m;
	// 	for (int i = n; i > k; --i) {
	// 		PrimeUtils::primeFactorize(i);
	// 		for (int j = 0; j < PrimeUtils::primeFactorCount; ++j) {
	// 			p = PrimeUtils::primeFactors[j];
	// 			m[p] += PrimeUtils::powers[j];
	// 		}
	// 	}
	// 	for (int i = 2; i <= n - k; ++i) {
	// 		PrimeUtils::primeFactorize(i);
	// 		for (int j = 0; j < PrimeUtils::primeFactorCount; ++j) {
	// 			p = PrimeUtils::primeFactors[j];
	// 			m[p] -= PrimeUtils::powers[j];
	// 		}
	// 	}

	// 	auto x = 1LL;
	// 	for (auto &e : m) {
	// 		for (int k = 0; k < e.second; ++k) {
	// 			x *= e.first;
	// 		}
	// 	}
	// 	return x;
	// }

	auto factorial(int n) {
		auto x = 1LL;
		if (n <= 1) {
			return x;
		}
		for (int i = 2; i <= n; ++i) {
			x *= i;
		}
		return x;
	}

	auto nthPermutation(string s, int n) {
		if (n <= 1) {
			return s;
		}
		int x = 1, y = 2;
		while (x * y < n) {
			x *= y;
			++y;
		}
		--y;
		if (n % x == 0) {
			return s[n/x-1]+nthPermutation(s.substr(0, n/x-1)+s.substr(n/x), n-x);
		} else {
			return s[n/x]+nthPermutation(s.substr(0, n/x)+s.substr(n/x+1), n-x*(n/x));
		}
	}


	auto nthPermutationX() {
		const int N = 1e6;
		int n = N;
		string s = "0123456789";
		string ans = "", t;
		int x, y, p;
		while (n > 1) {
			x = 1;
			y = 2;
			while (x * y < n) {
				x *= y;
				++y;
			}
			p = n / x;
			if (n % x == 0) {
				--p;
				n -= x;
			} else {
				n -= x * (n / x);
			}
			ans += s[p];
			t = s.substr(0, p) + s.substr(p + 1);
			s = t;
		}
		return ans + s;
	}


}

using namespace CombinatoricsUtils;

int main() {
	freopen("output.txt", "w+", stdout);
	vector <int> v =  {
		2, 3, 4, 5, 16, 24, 23, 25, 1, 719, 720, 721
	};
	cout<<nthPermutation("0123456789", 1e6);

	return 0;
}