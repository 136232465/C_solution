#include <unordered_map>
#include <vector>
using namespace std;
//leetcode 554  Brick Wall
//time O(n)
//space O(n)


class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> wallwidth;
		int maxwalls = 0;
		for (auto i : wall){
			int width = 0;
			for (int j = 0; j < i.size() - 1; ++j){
				width += i[j];
				++wallwidth[width];
				maxwalls = max(maxwalls, wallwidth[width]);
			}
		}

		return wall.size() - maxwalls;
	}
};