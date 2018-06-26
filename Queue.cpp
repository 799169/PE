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




struct Queue {

	const int N = 100;
	int a[N];
	int qf, qb;

	// a[qf ... qb-1] contain elemnts of the queue
	// front -> a[qf]
	// back -> a[qb - 1]

	Queue() {
		qf = 0;
		qb = 0;
	}

	void push(int x) {
		a[qb] = x;
		++qb;
	}

	int length() {
		return qb - qf;
	}

	int pop() {
		int x = a[qf];
		++qf;
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

