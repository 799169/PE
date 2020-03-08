#include "DebugUtils.cpp"

#ifndef __IU

#define __IU


namespace IntegerUtils {

// if x is pandigital, then all permutations of its digits are also pandigital
// can sort / create a hask

bool is1to9Pandigital(int n) {
	Assert(n >= 0);
	bool a[9];
	int g = 0, d;
	fill(all(a), false);
	while (n > 0) {
		d = (n % 10) - 1;
		if (a[d]) {
			return false;
		}
		a[d] = true;
		n /= 10;
		++g;
	}
	return g == 9;
}

bool is0to9Pandigital(Long n) {
	Assert(n >= 0);
	bool a[10];
	int g = 0, d;
	fill(all(a), false);
	while (n > 0) {
		d = (n % 10);
		if (a[d]) {
			return false;
		}
		a[d] = true;
		n /= 10;
		++g;
	}
	return g == 10;
}

bool isPalindrome(Long x) {
	Assert(x >= 0);
	// 10 = max no. of digits in int
	// change to 19 / 20 for Long, 10 for int
	int a[20], n = 0, i = 0;
	while (x > 0) {
		a[n] = x % 10;
		++n;
		x /= 10;
	}
	--n;
	while (i < n) {
		if (a[i] != a[n]) {
			return false;
		}
		++i;
		--n;
	}
	return true;
}

Long reverseInt(Long x) {
	Long r = 0;
	while (x > 0) {
		r = (r * 10) + (x % 10);
		x /= 10;
	}
	return r;
}

int sumOfDigits(Long x) {
	Assert(x >= 0);
	int s = 0;
	while (x > 0) {
		s += (x % 10);
		x /= 10;
	}
	return s;
}

int numOfDigits(Long x) {
	Assert(x >= 0);
	int s = 0;
	while (x > 0) {
		++s;
		x /= 10;
	}
	return s;
}


// x, y -> x y
Long concatenate(int x, int y) {
	Assert(x > 0 and y > 0);
	int z = y;
	while (z > 0) {
		z /= 10;
		x *= 10;
	}
	return x + y;
}


// returns x ^ y
Long powi(Long x, Long y) {
	Assert(x >= 0 and y >= 0);
	Long ans = 1;
	while (y > 0) {
		if (y & 1) {
			--y;
			Assert(LLONG_MAX / x >= ans);
			ans *= x;
		}
		y >>= 1;
		Assert(LLONG_MAX / x <= x);
		x *= x;
	}
	return ans;
}

Long powi2(Long x, Long y) {
	Assert(x >= 0 and y >= 0);
	Long ans = 1;
	for (Long i = 0; i < y; ++i) {
		ans *= x;
	}
	return ans;
}


// returns x ^ y (mod md) (check for no overflow: int -> Long)
Long powMod(int x, int y, int md) {
	Long ans = 1;
	while (y > 0) {
		if (y & 1) {
			--y;
			ans *= x;
			ans %= md;
		}
		y >>= 1;
		x *= x;
		x %= md;
	}
	return ans;
}


// 0b1101 == 13
string toBinary(Long n) {
	bitset<64> b(n);
	string s = b.to_string();
	int i = 0;
	while (s[i] == '0' and i < 64) {
		++i;
	}
	return s.substr(i);
	// return b.to_string();
}



};


using namespace IntegerUtils;

struct Solver {

	void solve() {
		// tr(is0to9Pandigital(12345667890L));
		tr(reverseInt(122798221L));
	}	

} solver;

// int main() {
// 	#ifdef LOCAL_DEFINE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w+", stdout);
// 	#else
// 		ios_base::sync_with_stdio(false);
// 		cin.tie(nullptr);
// 		cout.tie(nullptr);
// 	#endif	
// 	auto t1 = chrono::high_resolution_clock::now();
// 	solver.solve();
// 	auto t2 = chrono::high_resolution_clock::now();
// 	chrono::duration<double> t = t2 - t1;
// 	#ifdef LOCAL_DEFINE
// 		cout << "\nTime taken: " << fixed;
// 		cout << setprecision(5) << t.count() << "s\n\n";
// 	#endif
// 	return 0;
// }



#endif
