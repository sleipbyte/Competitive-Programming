class DSU {
private:
	vector<int>parent, size;

public:

	DSU(int n) {
		for (int i = 1; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}

	int findPar(int node) {
		if (parent[node] == node)
			return node;
		parent[node] = findPar(parent[node]); // Path Compression
	}

	void addUnion(int u, int v) {
		int pu = findPar(u);
		int pv = findPar(v);

		if (pu == pv) // Do nothing since it belongs to the same group
			return;

		if (size[pu] < size[pv]) { // size compression
			parent[pu] = pv;
			size[pv] += size[pu];
		} else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
	}
};