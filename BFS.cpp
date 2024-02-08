#include <iostream>
#include <vector>
#include <queue>

const int vertices = 1024;
int n, m;
std::vector<int> gr[vertices];
bool used[vertices];
std::queue<int> spis;
int levels[vertices];

int bfs(int start) {

	used[start] = 1;
	spis.push(start);

	int level = 1;
	int nodesOfLevel = 1;

	while (!spis.empty()) {

		int node = spis.size();
		levels[node] = level;

		spis.pop();

		nodesOfLevel--;

		for (int i = 0; i < gr[node].size(); i++) {
			if (!used[gr[node][i]]) {
				used[gr[node][i]] = 1;
				spis.push(gr[node][i]);
			}
		}

		if (nodesOfLevel == 0) {
			level++;
			nodesOfLevel = spis.size();
		}
	}

}

int main() {
	std::cin >> n >> m;

	int from, to;
	for (int i = 0; i < m; i++) {
		std::cin >> from >> to;
		gr[from].push_back(to);
		gr[to].push_back(from);
	}

	bfs(1);
	for (int i = 1; i <= n; i++) {
		std::cout << levels[i] << " " ;
	}
}