#include <unordered_map>
#include <vector>
using namespace std;
//leetcode 554  Brick Wall
//time O(n)
//space O(n)
// There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

// The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

// If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
// Input: 
// [[1,2,2,1],
 // [3,1,2],
 // [1,3,2],
 // [2,4],
 // [3,1,2],
 // [1,3,1,1]]
// Output: 2
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