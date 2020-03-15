#include "DebugUtils.cpp"


const int MAXN = 1e7;
const int SQRTMAXN = sqrt(MAXN);
const int MAXS = MAXN / 3;	// number of candidates to be checked; all are of the form 6k + 1 or 6k - 1
const int MAXP = MAXN / 10;	// max number of primes expected <= MAXN
bitset<MAXS> sieve;
// bool sieve[MAXS];
int primes[MAXP] = {2, 3}, numOfPrimes = 2;

// MAXN=1e5 numOfPrimes=   9592 (0.09592)	< 10% numbers are prime
// MAXN=1e6 numOfPrimes=  78498 (0.078498)	<  8% numbers are prime
// MAXN=1e7 numOfPrimes= 664579 (0.0664579) 0.05seconds
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
	sieve.set();
	for (int i = 0; i < MAXS; ++i) {
		if (int j = getNumber(i); sieve[i]) {
			if (j > SQRTMAXN) break;
			for (int k = j * j; k <= MAXN; k += 6 * j) sieve[(k - 4) / 3] = false;
			for (int k = j * j + 2 * j * ((i & 1) + 1); k <= MAXN; k += 6 * j) sieve[(k - 5) / 3] = false;
		}
	}
	for (int i = 0; i < MAXS; ++i)
		if (sieve[i]) primes[numOfPrimes++] = getNumber(i);
}



const int N = 1e7;

bool isPermutaion(int x, int y) {
	int a[10], d;
	fill_n(a, 10, 0);
	while (x > 0) {
		d = (x % 10);
		++a[d];
		x /= 10;
	}
	while (y > 0) {
		d = (y % 10);
		--a[d];
		if (a[d] < 0) {
			return false;
		}
		y /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		if (a[i] != 0) {
			return false;
		}
	}
	return true;
}



void solve() {
	generatePrimes();
	LD best = 0, curr;
	int ans = 6, n, m, phi;
	for (int nn = 2; nn <= N; ++nn) {
		n = nn;
		m = sqrt(n) + 1;
		curr = 1, phi = n;
		for (int i = 0; i < numOfPrimes; ++i) {
			int p = primes[i];
			if (p > m) {
				if (n > 1) {
					curr *= (n - 1.0L) / n;
					phi /= n;
					phi *= (n - 1);
				}
				break;
			}
			if (n % p == 0) {
				n /= p;
				phi /= p;
				phi *= (p - 1);
				while (n % p == 0) {
					n /= p;
				}
				curr *= (p - 1.0L) / p;
			}
		}
		if (isPermutaion(nn, phi) and curr > best) {
			best = curr;
			ans = nn;
		}
	}
	tr(ans);
	return;
}

// ans=8319823 

// Time taken: 12.20889s

