#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>
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
	#include "DebugUtils.h"
#endif


namespace BinarySearch {


	int indexOf(int *a, int n, int b) {
		int x = 0, y = n - 1, z;
		while (x <= y) {
			z = (x + y) / 2;
			if (a[z] == b) {
				return z;
			}
			if (a[z] > b) {
				y = z - 1;
			} else {
				x = z + 1;
			}
		}
		return -1;
	}

	// Index of largest x in a such that x <= p
	int searchFloor(int *a, int n, int b) {
		if (b >= a[n - 1]) {
			return n - 1;
		}
		if (b < a[0]) {
			return -1;
		}
		int x = 0, y = n - 1, z, w;
		while (x <= y) {
			z = (x + y) / 2;
			if (a[z] == b) {
				return z;
			}
			if (a[z] > b) {
				y = z - 1;
			} else {
				w = z;
				x = z + 1;
			}
		}
		return w;
	}

	// Index of smallest x in a such that x >= p
	int searchCeil(int *a, int n, int b) {
		if (b > a[n - 1]) {
			return -1;
		}
		if (b <= a[0]) {
			return 0;
		}
		int x = 0, y = n - 1, z, w;
		while (x <= y) {
			z = (x + y) / 2;
			if (a[z] == b) {
				return z;
			}
			if (a[z] > b) {
				w = z;
				y = z - 1;
			} else {
				x = z + 1;
			}
		}
		return w;
	}

}



int main() {
	#ifdef LOCAL
		freopen("output.txt", "w+", stdout);
		freopen("input.txt", "r", stdin);
	#endif

	return 0;
}

/***********************
    Answer:     748317
 Time taken:   0.05900s
 ************************/