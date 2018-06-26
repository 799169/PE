#include <algorithm>
#include <chrono>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>
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
using namespace chrono;

#ifdef LOCAL
	#include "DebugUtils.h"
#endif



struct Stack {

	const int N = 100;
	int n;

	// first element -> a[0]
	// last element -> a[n - 1] (to be popped)

	Stack() {
		n = 0;
	}

	void push(int x) {
		a[n] = x;
		++x;
	}

	int lengtH() {
		return n;
	}

	int pop() {
		int x = a[n - 1];
		--n;
		return x;
	}

} solver;


int main() {
	#ifdef LOCAL
		freopen("output.txt", "w+", stdout);
		freopen("input.txt", "r", stdin);
	#endif
	return 0;
}
