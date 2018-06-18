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


struct Problem31 {


	auto solve() {
		const int N = 200, K = 8;
		long long a[N + 1][K];
		vector <int> v =  {
			1, 2, 5, 10, 20, 50, 100, 200
		};
		for (int i = 0; i <= N; ++i) {
			a[i][0] = 1;
			for (int j = 1; j < K; ++j) {
				a[i][j] = 0;
			}
		}
		for (int j = 0; j < K; ++j) {
			a[1][j] = 1;
		}
		for (int j = 1; j < K; ++j) {
			++a[v[j]][j];
		}
		for (int i = 2; i <= N; ++i) {
			for (int j = 1; j < K; ++j) {
				a[i][j] += a[i][j - 1];
				int k;
				for (k = v[j]; k < i; k += v[j]) {
					a[i][j] += a[i - k][j - 1];
				}
				if (k == i && v[j] != i) {
					++a[i][j];
				}
			}
		}
		return a[N][K - 1];
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
    Answer:      73682
 Time taken:   0.00000s
***********************/
