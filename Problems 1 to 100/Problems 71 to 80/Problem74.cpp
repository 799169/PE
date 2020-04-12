#include <bits/stdc++.h>

using namespace	std;

#define rp(i, n)    for (int i = 0; i < (int) (n); ++i)
#define fr(i, x, n) for (int i = (x); i < (int) (n); ++i) 
#define rf(i, x, y) for (int i = (x); i >= (int) (y); --i) 


namespace Solver {

	const int N = 1e7;
	bitset<N> visited, done;
	char cycleLength[N];
	const int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

	// sum of factorial of digits
	int calc(int x) { int y = 0; while (x > 0) { y += factorial[x % 10]; x /= 10; } return y; }

	// sort digits of 'x' in decreasing (non-increasing) order, eg. 618 -> 861
	int calc2(int x) {
		int a[10], y = 0; fill_n(a, 10, 0); while (x > 0) { ++a[x % 10]; x /= 10; }
		rf(i, 9, 0) while (a[i] > 0) { y = y * 10 + i; --a[i]; }
		return y;
	}

	int calculateLength(int x) {
		int y = calc2(x), ans = 0;
		while(!done[y]) { y = calc2(calc(y)); ++ans; }
		return ans + cycleLength[y];
	}

	int solve() {
		int zz, z, mem[80], memn, cnt, x, y, cur, ans = 0;
		rf(d1, 9, 0) rf(d2, d1, 0) rf(d3, d2, 0) rf(d4, d3, 0) rf(d5, d4, 0) rf(d6, d5, 0) rf(d7, d6, 0) {
			zz = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d5*100 + d6*10 + d7; z = zz*10;
			do {
				z /= 10; memn = 0; cnt = 1; x = z;
				if (visited[z]) continue;
				while (!visited[x]) {
					mem[memn++] = x; cycleLength[x] = cnt; visited[x] = 1; y = calc2(calc(x)); x = y; ++cnt;
				}
				cur = cnt - cycleLength[x];
				int k = 0;
				rp(i, memn) if (mem[i] == x) { k=i; fr(j, i, memn) { cycleLength[mem[j]] = cur; done[mem[j]] = 1; } break; }
				rp(j, k) { cycleLength[mem[j]] = cur+k-j; done[mem[j]]=1; }
			} while (z % 10 == 0 and z > 0);
		}
		fr(i, 0, 1e6) if (calculateLength(i) == 60) ++ans;
		return ans;
	}

};


int main() {
	auto t1 = chrono::high_resolution_clock::now(); 
	cout << Solver::solve() << endl;
	auto t2 = chrono::high_resolution_clock::now(); 
	chrono::duration<double> t = t2 - t1;
	cout << "\nTime taken: " << fixed << setprecision(5) << t.count() << "s\n";
	return 0;
}





// 402
// Time taken: 0.76582s
