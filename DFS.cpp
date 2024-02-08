#include <iostream>
#include <vector>

const int VERTICES = 1024;
int n, m;
std::vector<int> gr[VERTICES];

int start, end;

bool used[VERTICES];

void dfs(int node) {
	used[node] = 1;
	for (int i = 0; i < gr[node].size(); i++) {
		if (!used[gr[node][i]]) dfs(gr[node][i]);
	}
}

int main() {

	std::cin >> n >> m;
	
	int from, to;
	for (int i = 0; i < n; i++) {
		std::cin >> from >> to;
		gr[from].push_back(to);
		gr[to].push_back(from);
	}

	std::cin >> start >> end;

	dfs(start);

	if (used[end] == 1) {
		std::cout << "There is a road";
	}
}