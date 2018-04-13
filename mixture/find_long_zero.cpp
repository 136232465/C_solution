// find longest sum is 0;
//[1,2,-2,0,4,1]
//return 3(2,0)

class Solution{
public:
	int getlong_num(vector<int> dst){
		if (dst.empty()){
			return 0;
		}
		map<int, int> dp;
		dp[0] = 0;
		int sum = 0;
		int res = 0;
		for (int i = 1; i <= dst.size(); ++i){
			sum += dst[i-1];
			auto it = dp.find(sum);
			if (it == dp.end()){
				dp[sum] = i;
			} else {
				res = max(res, i - it->second);
			}
		}
		return res;
	}
};