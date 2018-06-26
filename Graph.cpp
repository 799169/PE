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




struct Graph {

	static const int N = 10;
	vector <int> adj[N];
	bool visited[N];
	int parent[N];

	Graph() {

	}

	void addEdge(int i, int j) {
		addDirectedEdge(i, j);
		addDirectedEdge(j, i);
	}

	void addDirectedEdge(int i, int j) {
		adj[i].push_back(j);
	}

	void dfs() {
		for (int k = 0; k < N; ++k) {
			visited[k] = false;
		}
		for (int k = 0; k < N; ++k) {
			if (!visited[k]) {
				parent[k] = k;
				dfs(k);
			}
		}
	}

	void dfs(int i) {
		visited[i] = true;
		for (auto e : adj[i]) {
			if (!visited[e]) {
				parent[e] = i;
				dfs(e);
			}
		}
	}

	bool hasPath(int i, int j) {
		for (int k = 0; k < N; ++k) {
			visited[k] = false;
		}
		dfs(i);
		return visited[j];
	}

	void printPath(int i, int j) {
		parent[i] = i;
		while (parent[j] != i) {
			cout << j << " <- ";
			j = parent[j];
		}
	}

	void print() {
		for (int i = 0; i < N; ++i) {
			if (!adj[i].empty()) {
				cout << i << " : ";
				for (int j = 0; j < adj[i].size(); ++j) {
					cout << adj[i][j] << ' ';
				}
				cout << '\n';
			}
		}
	}



} solver;


int main() {
	#ifdef LOCAL
		freopen("output.txt", "w+", stdout);
		freopen("input.txt", "r", stdin);
	#endif
	Graph g;
	return 0;
}

/***********************
    Answer:     748317
 Time taken:   0.05900s
 ************************/