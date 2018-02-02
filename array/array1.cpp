//leetcode 714
//Best Time to Buy and Sell Stock with Transaction Fee
//time O(n)
//space O(1)

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int i1 = 0, i2 = INT_MIN;
		for (int p : prices) {
			int temp = i1;
			i1 = max(i1, i2 + p);
			i2 = max(i2, temp - p - fee);
		}
		return i1;
	}
};

//i1----sail
//i2----buy