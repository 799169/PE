#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

typedef long long Long;
typedef vector <int> IntVector;


struct Problem53 {

	static const int N = 100;
	Long a[N + 1][N + 1];
	int i, j, c, b;

	auto solve() {
		c = 0;
		a[0][0] = 1;
		for (i = 1; i <= N; ++i) {
			a[i][0] = 1;
			b = 0;
			for (j = 1; j <= i / 2 + 4; ++j) {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
				if (a[i][j] > 1e6 and b == 0) {
					c += 2 * ((i / 2) - (j - 1));
					if (i % 2 == 0) {
						--c;
					}
					b = 1;
				}
			}
		}
		return c;
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
    Answer:       4075
 Time taken:   0.00000s
************************/
