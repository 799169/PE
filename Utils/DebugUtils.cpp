#include <bits/stdc++.h>
#include "Print.cpp"
#include "Typedefs.cpp"

using namespace std;

typedef stringstream tss;
typedef istream_iterator<string> iis;

#define all(x) begin(x), end(x)

#define tr(x...) { string _s = #x; replace(all(_s), ',', ' '); tss _ss(_s); iis _it(_ss); trx(_it, x); }

void trx(iis it) { cout << endl; }

template <class T, class... U>
void trx(iis it, T a, U... u) {
	cout << *it << '=' << toString(a) << ' ';
	// cout << *it << '=' << a << ' ';
	trx(++it, u...);
}

#define Assert(expr)  { if (!(expr))  { cout << "\n\nError on Line:" << __LINE__; exit(1);  } }

// returns true if the sum x + y overflows signed long type
bool sumOverflow(Long x, Long y) {
	return y > (LLONG_MAX - x);
}

bool productOverflow(Long x, Long y) {
	return y > LLONG_MAX / x;
}


// Assert(!productOverflow(LLONG_MAX>>3, 13));
// for containers, use prl(ts(a, 10));

// int main() {
// 	cout<<(2+3);
// 	return 0;
// }
