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

namespace ArrayUtils {

	template <class T> void fill(T *a, int n, const T x) {
		for (int i = 0; i < n; ++i) {
			a[i] = x;
		}
	}

	template <class T> void reverse(T *a, int n) {
		T x;
		for (int i = 0; i < n / 2; ++i) {
			x = a[i];
			a[i] = a[n - i - 1];
			a[n - i - 1] = x;
		}
	}

	template <class T> T sum(T *a, int n) {
		auto s = T();
		for (int i = 0; i < n; ++i) {
			s += a[i];
		}
		return s;
	}

	template <class T> long long product(T *a, int n) {
		auto p = 1LL;
		for (int i = 0; i < n; ++i) {
			p *= a[i];
		}
		return p;
	}

}

using namespace ArrayUtils;
