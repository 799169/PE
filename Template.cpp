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

using namespace std;
using namespace chrono;

#ifdef LOCAL
	#include "ArrayUtils.h"
	#include "BigInteger.h"
	#include "DebugUtils.h"
	#include "IntegerUtils.h"
	#include "PrimeUtils.h"
	#include "FibonacciUtils.h"
	freopen("input.txt", "w+", stdout);
	freopen("output.txt", "w+", stdout);
#endif

struct {

	auto solve() {
		return 1;
	}

} solver;

int main(int argc, char const *argv[]) {
	auto t1 = high_resolution_clock::now();
	auto ans = solver.solve();
	auto t2 = high_resolution_clock::now();
	duration <double> t = t2 - t1;
	cout << setw(12) << " Answer: " << setw(10) << ans;
	cout << "\n Time taken: " << setw(9) << fixed;
	cout << setprecision(5) << t.count() << "s\n\n";
	return 0;
}
