#include "DebugUtils.cpp"


// Find all primes <= MAXN and store them in primes[]
const int MAXN = 1e5;
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


bool isPrime(Long n) {
	if ((n & 1) == 0 or (n % 3) == 0 or n < 5) {
		return (n == 2) or (n == 3);
	}
	int m = sqrt(n) + 1, p;
	if (n <= MAXN) {
		return sieve[getIndex(n)];
	}
	for (int i = 0; i < numOfPrimes; ++i) {
		p = primes[i];
		if (p > m) {
			return true;
		}
		if (n % p == 0) {
			return false;
		}
	}
	return true;
}

bool isPrime2(Long n) {
	int m = sqrt(n) + 1;
	if ((n & 1) == 0 or (n % 3 == 0) or (n < 5)) {
		return (n == 2) or (n == 3);
	}
	for (int i = 0; i < n; ++i) {
		int j = 6 * i + 5;
		int k = j + 2;
		if (k > m) {
			return true;
		}
		if ((n % j == 0) or (n % k == 0)) {
			return false;
		}
	}
	return true;
}


const int MAXF = 10;	// max number of distinct prime factors we expect the number to have
int primeFactors[MAXF];
int powers[MAXF], numOfPrimeFactors;

void primeFactorize(int n) {
	numOfPrimeFactors = 0;
	int m = sqrt(n) + 1;
	for (int i = 0; i < numOfPrimes; ++i) {
		int p = primes[i];
		if (p > m) {
			if (n > 1) {
				primeFactors[numOfPrimeFactors] = n;
				powers[numOfPrimeFactors] = 1;
				++numOfPrimeFactors;				
			}
			return;
		}
		if (n % p == 0) {
			primeFactors[numOfPrimeFactors] = p;
			powers[numOfPrimeFactors] = 1;
			n /= p;
			while (n % p == 0) {
				n /= p;
				++powers[numOfPrimeFactors];
			}
			++numOfPrimeFactors;
		}
	}
}

int numOfFactors(int n) {
	primeFactorize(n);
	int ans = 1;
	for (int i = 0; i < numOfPrimeFactors; ++i) {
		ans *= (powers[i] + 1);
	}
	return ans;
}


/*
if need to calculate prime factorization for all numbers from 1 to n
then do dp

from factorization of m, do 
for p in primes:
	for i = 1 to 10:
		fac [m * (p^i)] = fac[m] with m(p) incremented by 'i'

*/

// void printFactors(int n) {
// 	int z = numOfFactors(n);
// 	int y = numOfPrimeFactors;
// 	int m = 1, j;
// 	fill(a, a + numOfPrimeFactors, 0);
// 	for (int x = 0; x < z / 2; ++x) {
// 		printf("%d  ", m);
// 		j = y - 1;
// 		++a[j];
// 		m *= primeFactors[j];
// 		while (a[j] > powers[j] && j >= 0) {
// 			a[j] = 0;
// 			m /= powi(primeFactors[j], powers[j]);
// 			--j;
// 			++a[j];
// 			m *= primeFactors[j];
// 		}
// 	}
// 	if (z % 2 == 1) {
// 		printf("%d", (int) sqrt(n));
// 	}
// 	printf("\n");
// }


struct Solvers {

	auto solve() {
		generatePrimes();
		// tr(numOfPrimes);
		// prl(ts(primes, 25));
		// IntVector v(primes, primes + numOfPrimes);
		// prl(ts(v, 25), (int)v.size());
		primeFactorize(5040);
		map<int, int> mp;
		for (int i = 0; i < numOfPrimeFactors; ++i) {
			mp[primeFactors[i]] = powers[i];
		}
		tr(mp);
		return 1;
	}	

} solverpu;



// int main() {
// 	#ifdef LOCAL_DEFINE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w+", stdout);
// 	#else
// 		ios_base::sync_with_stdio(false);
// 		cin.tie(nullptr);
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

