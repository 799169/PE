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

typedef istream_iterator <string> _iis;
typedef stringstream _tss;

#define tr(x...) { string _s = #x; replace(begin(_s), end(_s), ',', ' '); _tss _ss(_s); _iis _it(_ss); trx(_it, x); }

void trx(_iis it) { cout << endl; }

template <class T, class... U> void trx(_iis it, T a, U... u) {
	cout << *it << '=' << a << ' ';
	trx(++it, u...);
}

namespace DebugUtils  {

	void print() {
		cout << ' ';
	}

	void println() {
		cout << '\n';
	}

	template <class T> void print(const vector <T> &v) {
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}

	template <class T> void print(const T &t) {
		cout << t << ' ';
	}

	template <class T> void println(const T &t) {
		cout << t << '\n';
	}

	template <class T> void print(T *a, int n) {
		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	template <class T, class... U> void print(const T &t, const U... u) {
		print(t);
		print(u...);
	}

	template <class T, class... U> void println(const T &t, const U... u) {
		print(t);
		println(u...);
	}

}

using namespace DebugUtils;

