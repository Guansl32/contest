#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<std::vector<int>> adj(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	std::vector<i64> cnt(n + 1);
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		for (auto &v: adj[u]) {
			if (v == fa) continue;
			cnt[v] += cnt[u];
			dfs(v, u);
		}
	};

	while (q--) {
		int p, x;
		std::cin >> p >> x;
		cnt[p] += x;
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		std::cout << cnt[i] << " \n"[i == n];
	}

	return 0;
}