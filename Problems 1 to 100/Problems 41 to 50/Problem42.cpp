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


struct Problem42 {

	auto solve() {
		ifstream f("words.txt");
		string a;
		f >> a;
		int s = 0, n = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] >= 'A' && a[i] <= 'Z') {
				s += (a[i] - 'A' + 1);
			} else if (a[i] == ',') {
				if (isTriangular(s)) {
					++n;
				}
				s = 0;
			}
		}
		if (isTriangular(s)) {
			++n;
		}
		return n;
	}

	bool isTriangular(int x) {
		int n = (sqrt(8 * x + 1) - 1) / 2;
		return n * (n + 1) / 2 == x;
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
    Answer:        162
 Time taken:   0.00100s
************************/
