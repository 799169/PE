#include <bits/stdc++.h>

using namespace std;

typedef stringstream tss;
typedef istream_iterator <string> iis;

#define all(x) begin(x), end(x)

#define tr(x...) { string _s = #x; replace(all(_s), ',', ' '); tss _ss(_s); iis _it(_ss); trx(_it, x); }

void trx(iis it) { cout << endl; }

template <class T, class... U>
void trx(iis it, T a, U... u) {
	cout << *it << '=' << a << ' ';
	trx(++it, u...);
}

namespace DebugUtils  {

	template <class T>
	void print(const T t) {
		cout << t;
	}

	template <class T, class... U>
	void print(const T t, const U... u) {
		print(t);
		print(' ');
		print(u...);
	}

	void println() {
		cout << '\n';
	}

	template <class T>
	void println(const T t) {
		print(t);
		print('\n');
	}

	template <class T, class... U>
	void println(const T t, const U... u) {
		print(t);
		print(' ');
		println(u...);
	}

	template <class T, class U>
	void print(const pair <T, U> p) {
		print('{');
		print(p.first);
		print(",");
		print(p.second);
		print('}');
	}

	template <class T, class U>
	void println(const pair <T, U> p) {
		print(p);
		println();
	}

	template <class T>
	void print(vector <T> v, int n) {
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				print(' ');
			}
			print(v[i]);
		}
	}

	template <class T>
	void print(vector <T> v) {
		print(v, v.size());
	}


	template <class T>
	void println(vector <T> v, int n) {
		print(v, n);
		println();
	}

	template <class T>
	void println(vector <T> v) {
		print(v, v.size());
		println();
	}


	template <class T>
	void print(set <T> v, int n) {
		auto e = begin(v);
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				print(' ');
			}
			print(*e);
			++e;
		}
	}

	template <class T>
	void print(set <T> v) {
		print(v, v.size());
	}


	template <class T>
	void println(set <T> v, int n) {
		print(v, n);
		println();
	}

	template <class T>
	void println(set <T> v) {
		print(v, v.size());
		println();
	}

	template <class T, class U>
	void print(map <T, U> v, int n) {
		auto e = begin(v);
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				print(' ');
			}
			print(e -> first);
			print(':');
			print(e.second);
			++e;
		}
	}

	template <class T, class U>
	void print(map <T, U> v) {
		print(v, v.size());
	}


	template <class T, class U>
	void println(map <T, U> v, int n) {
		print(v, n);
		println();
	}

	template <class T, class U>
	void println(map <T, U> v) {
		print(v, v.size());
		println();
	}

	template <class T>
	void print(vector <T> *a, int n) {
		for (int i = 0; i < n; ++i) {
			println(a[i]);
		}
	}

	template <class T>
	void println(vector <T> *a, int n) {
		print(a, n);
		println();
	}

	template <class T>
	void print(T *a, int n) {
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				print(' ');
			}
			print(a[i]);
		}
	}

	template <class T>
	void println(T *a, int n) {
		print(a, n);
		println();
	}

};

using namespace DebugUtils;


int main() {
	freopen("output.txt", "w+", stdout);

	return 0;
}
