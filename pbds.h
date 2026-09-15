#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

/*
	pbds supports following functions

	pbds A;

	// Inserting elements
	A.insert(1);

	// finding kth element
	cout << "0th element: " << *A.find_by_order(0) << endl;

	// finding number of elements smaller than X
	cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 1

	// lower bound -> Lower Bound of X = first element >= X in the set
	cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;

	// Upper bound -> Upper Bound of X = first element > X in the set
	cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;

	// // Remove elements - 2nd query
	A.erase(0);
*/