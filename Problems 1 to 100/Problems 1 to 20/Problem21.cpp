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


struct Problem20 {

	auto solve() {
		const int N = 10000;
		int a[N], s = 0;
		a[0] = a[1] = 0;
		for (int i = 2; i < N; ++i) {
			a[i] = 1;
		}
		for (int i = 2; i < N / 2; ++i) {
			for (int j = 2 * i; j < N; j += i) {
				a[j] += i;
			}
		}
		for (int i = 2; i < N; ++i) {
			if (a[i] < N) {
				if (a[a[i]] == i && a[i] != i) {
					s += i;
				}
			}
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
    Answer:      31626
 Time taken:   0.00000s
***********************/
