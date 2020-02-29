#include <bits/stdc++.h>

#ifdef LOCAL_DEFINE
	#include "DebugUtils.h"
#endif	


using namespace std;
using namespace chrono;

using Long = long long;
using LD = long double;

// Find all primes <= MAXN and store them in primes[]
const int MAXN = 1e8;
const int SQRTMAXN = sqrt(MAXN);
const int MAXS = MAXN / 3;
bitset<MAXS> sieve;
// bool sieve[MAXS];
int primes[MAXN / 10] = {2, 3}, numOfPrimes = 2;

// MAXN=1e5 numOfPrimes=9592 (0.09592)		< 10% numbers are prime
// MAXN=1e6 numOfPrimes=78498 (0.078498)	<  8% numbers are prime
// MAXN=1e7 numOfPrimes=664579 (0.0664579) 0.05seconds

// MAXN=1e8 numOfPrimes=5761455 (0.0576146) 0.5seconds with bitset 0.8seconds with bool[]



// if i is even (0, 2, 4): then the index i in sieve holds 3 * i + 5
// if i is odd  (1, 3, 5): then the index i in sieve holds 3 * i + 4
inline int getNumber(int i) {
	return 3 * i + 5 - (i & 1);
}

// if n == 1 (mod 6) then n is at index (n - 4) / 3
// if n == 5 (mod 6) then n is at index (n - 5) / 3
inline int getIndex(int n) {
	return (n % 6 == 1) ? (n - 4) / 3 : (n - 5) / 3;
}

// all primes <= MAXN
void generatePrimes() {
	// fill(sieve, sieve + MAXS, true);
	sieve.set();
	for (int i = 0; i < MAXS; ++i) {
		// if i odd ,  j == 1 (mod 6),  j * j == 1 (mod 6),  j * j + 4 * j == 5 (mod 6)
		// if i even,  j == 5 (mod 6),  j * j == 1 (mod 6),  j * j + 2 * j == 5 (mod 6)
		// tr(i, getNumber(i), sieve[i])
		if (sieve[i]) {
			int j = getNumber(i);
			if (j > SQRTMAXN) {
				break;
			}
			for (int k = j * j; k <= MAXN; k += 6 * j) {
				sieve[(k - 4) / 3] = false;
			}
			for (int k = j * j + 2 * j * ((i & 1) + 1); k <= MAXN; k += 6 * j) {
				sieve[(k - 5) / 3] = false;
			}
		}
	}
	for (int i = 0; i < MAXS; ++i) {
		if (sieve[i]) {
			primes[numOfPrimes] = getNumber(i);
			++numOfPrimes;
		}
	}
	while (primes[numOfPrimes - 1] > MAXN) {
		--numOfPrimes;
	}
}


struct Solver {

	auto solve() {
		generatePrimes();
		return 1;
	}	

} solver;

int main() {
	#ifdef LOCAL_DEFINE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w+", stdout);		
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
	#endif	
	auto t1 = high_resolution_clock::now();
	auto ans = solver.solve();
	auto t2 = high_resolution_clock::now();
	duration<double> t = t2 - t1;
	cout << setw(15) << " Answer: " << setw(10) << ans;
	cout << "\n Time taken: " << setw(12) << fixed;
	cout << setprecision(5) << t.count() << "s\n\n";
	return 0;
}

 //       Answer:     906609
 // Time taken:      0.00000s

