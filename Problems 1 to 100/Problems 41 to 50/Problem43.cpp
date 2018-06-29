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

namespace IntegerUtils {

	int length(IntL n) {
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

struct Problem43 {

	static const int MAXD = 9;
	bool z[MAXD + 1];

	auto solve() {
		IntL xa, xb, xc, xd, xe, xf, xg, xh, ans = 0LL;
		for (int a = 17; a <= 987; a += 17) {
			xa = a;
			if (hasRepeatedDigits(xa)) {
				continue;
			}
			for (int b = 0; b <= 9; ++b) {
				xb = b * 1e3 + xa;
				if ((xb / 10) % 13 != 0) {
					continue;
				}
				if (IntegerUtils::length(xb) < 3) {
					continue;
				}
				if (hasRepeatedDigits(xb)) {
					continue;
				}
				for (int c = 0; c <= 5; c += 5) {
					xc = c * 1e4 + xb;
					if ((xc / 100) % 11 != 0) {
						continue;
					}
					if (IntegerUtils::length(xc) < 4) {
						continue;
					}
					if (hasRepeatedDigits(xc)) {
						continue;
					}
					for (int d = 0; d <= 9; ++d) {
						xd = d * 1e5 + xc;
						if ((xd / 1000) % 7 != 0) {
							continue;
						}
						if (IntegerUtils::length(xd) < 5) {
							continue;
						}
						if (hasRepeatedDigits(xd)) {
							continue;
						}
						for (int e = 0; e <= 8; e += 2) {
							xe = e * 1e6 + xd;
							if (IntegerUtils::length(xe) < 6) {
								continue;
							}
							if (hasRepeatedDigits(xe)) {
								continue;
							}
							for (int f = 0; f <= 9; ++f) {
								xf = f * 1e7 + xe;
								if ((xf / 100000) % 3 != 0) {
									continue;
								}
								if (IntegerUtils::length(xf) < 7) {
									continue;
								}
								if (hasRepeatedDigits(xf)) {
									continue;
								}
								for (int g = 0; g <= 9; ++g) {
									xg = g * 1e8 + xf;
									if (IntegerUtils::length(xg) < 8) {
										continue;
									}
									if (hasRepeatedDigits(xg)) {
										continue;
									}
									for (int h = 1; h <= 9; ++h) {
										xh = h * 1e9 + xg;
										if (IntegerUtils::length(xh) < 9) {
											continue;
										}
										if (hasRepeatedDigits(xh)) {
											continue;
										}
										ans += xh;
									}
								}
							}
						}
					}
				}
			}
		}
		return ans;
	}

	bool hasRepeatedDigits(IntL x) {
		for (int i = 0; i <= MAXD; ++i) {
			z[i] = false;
		}
		while (x > 0) {
			if (z[x % 10]) {
				return true;
			}
			z[x % 10] = true;
			x /= 10;
		}
		return false;
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

/************************
    Answer: 16695334890
 Time taken:   0.00000s
************************/
