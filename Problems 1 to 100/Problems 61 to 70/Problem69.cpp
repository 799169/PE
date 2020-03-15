#include "DebugUtils.cpp"


const int MAXN = 1e4;
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



const int N = 1e6;


void solve() {
	generatePrimes();
	LD best = 3, curr;
	int ans = 6, n, m;
	for (int nn = 1; nn <= N; ++nn) {
		n = nn;
		m = sqrt(n) + 1;
		curr = 1;
		for (int i = 0; i < numOfPrimes; ++i) {
			int p = primes[i];
			if (p > m) {
				if (n > 1) {
					curr *= (p - 1.0L) / p; // should be n - 1 / n; replace p |---> n ?
				}
				break;
			}
			if (n % p == 0) {
				n /= p;
				while (n % p == 0) {
					n /= p;
				}
				curr *= (p - 1.0L) / p;
			}
		}
		if (curr < best) {
			best = curr;
			ans = nn;
		}
	}
	tr(ans);
	return;
}


ans=510510 

Time taken: 0.53138s
