﻿//leetcode 15 // 3SUM
//time O（n²）


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i){
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back){
				int sum = nums[front] + nums[back];
				if (sum < -nums[i]){
					++front;
				}
				else if (sum > -nums[i]){
					--back;
				}
				else {
					vector<int> trip = { nums[i], nums[front], nums[back] };
					res.push_back(trip);
					while (front < back && nums[front] == trip[1])++front;
					while (front < back && nums[back] == trip[2])--back;
				}
			}
			while (i + 1 < nums.size() && nums[i + 1] == nums[i]){
				i++;
			}
		}
		return res;
	}
};


//use front pointer and  back pointer,