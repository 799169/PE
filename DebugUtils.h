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
	void pr(const T t) {
		cout << t;
	}

	template <class T, class... U>
	void pr(const T t, const U... u) {
		pr(t);
		pr(' ');
		pr(u...);
	}

	void prn() {
		cout << '\n';
	}

	template <class T>
	void prn(const T t) {
		pr(t);
		pr('\n');
	}

	template <class T, class... U>
	void prn(const T t, const U... u) {
		pr(t);
		pr(' ');
		prn(u...);
	}

	template <class T, class U>
	void pr(const pair <T, U> p) {
		pr('{');
		pr(p.first);
		pr(",");
		pr(p.second);
		pr('}');
	}

	template <class T, class U>
	void prn(const pair <T, U> p) {
		pr(p);
		prn();
	}

	template <class T>
	void pr(vector <T> v, int n) {
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				pr(' ');
			}
			pr(v[i]);
		}
	}

	template <class T>
	void pr(vector <T> v) {
		pr(v, v.size());
	}


	template <class T>
	void prn(vector <T> v, int n) {
		pr(v, n);
		prn();
	}

	template <class T>
	void prn(vector <T> v) {
		pr(v, v.size());
		prn();
	}


	template <class T>
	void pr(set <T> v, int n) {
		auto e = begin(v);
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				pr(' ');
			}
			pr(*e);
			++e;
		}
	}

	template <class T>
	void pr(set <T> v) {
		pr(v, v.size());
	}


	template <class T>
	void prn(set <T> v, int n) {
		pr(v, n);
		prn();
	}

	template <class T>
	void prn(set <T> v) {
		pr(v, v.size());
		prn();
	}

	template <class T, class U>
	void pr(map <T, U> v, int n) {
		auto e = begin(v);
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				pr(' ');
			}
			pr(e -> first);
			pr(':');
			pr(e.second);
			++e;
		}
	}

	template <class T, class U>
	void pr(map <T, U> v) {
		pr(v, v.size());
	}


	template <class T, class U>
	void prn(map <T, U> v, int n) {
		pr(v, n);
		prn();
	}

	template <class T, class U>
	void prn(map <T, U> v) {
		pr(v, v.size());
		prn();
	}

	template <class T>
	void pr(vector <T> *a, int n) {
		for (int i = 0; i < n; ++i) {
			prn(a[i]);
		}
	}

	template <class T>
	void prn(vector <T> *a, int n) {
		pr(a, n);
		prn();
	}

	template <class T>
	void pr(T *a, int n) {
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				pr(' ');
			}
			pr(a[i]);
		}
	}

	template <class T>
	void prn(T *a, int n) {
		pr(a, n);
		prn();
	}

};

using namespace DebugUtils;


int main() {
	freopen("output.txt", "w+", stdout);

	return 0;
}
