const int N = 200005;

struct Segtree
{
	int max_seg;
};

Segtree t[4 * N];

Segtree combine(Segtree a, Segtree b)
{
	Segtree res;

	res.max_seg = max({a.max_seg, b.max_seg});

	return res;
}

void build(int node, int leftmost, int rightmost, int a[])
{
	if (leftmost == rightmost)
	{
		t[node].max_seg = a[leftmost];
		return;
	}

	int mid = (leftmost + rightmost) / 2;

	build(2 * node, leftmost, mid, a);

	build(2 * node + 1, mid + 1, rightmost, a);

	t[node] = combine(t[2 * node], t[2 * node + 1]);
}

void update(int node, int leftmost, int rightmost, int index, int val)
{
	if (leftmost == index &&  rightmost == index)
	{
		t[node].max_seg = val;
		return;
	}

	if (index > rightmost || index < leftmost)
		return;

	int mid = (leftmost + rightmost) / 2;

	update(2 * node, leftmost, mid, index, val);

	update(2 * node + 1, mid + 1, rightmost, index, val);

	t[node] = combine(t[2 * node], t[2 * node + 1]);

}

Segtree Query(int node, int leftmost , int rightmost, int l , int r)
{
	if (l > rightmost || r < leftmost)
	{
		Segtree res;

		res.max_seg = 0;

		return res;
	}

	if (l <= leftmost && r >= rightmost)
	{
		return t[node];
	}

	int mid = (leftmost + rightmost) / 2;

	return combine(Query(2 * node, leftmost, mid, l, r), Query(2 * node + 1, mid + 1, rightmost, l, r));
}