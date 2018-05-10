//leetcode 207
//Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> course(numCourses);
        vector<int> level(numCourses,0);
        for (auto i : prerequisites){
            course[i.second].insert(i.first);
        }
        for (auto m : course){
            for (auto i : m){
                level[i]++;
            }
        }
        for (int i = 0; i < course.size(); ++i){
            int j = 0;
            for (; j < numCourses; ++j){
                if(level[j] == 0){
                    break;
                }
            }
            if (j == numCourses){
                return false;
            }
            level[j] = -1;
            for ( auto k : course[j]){
                level[k]--;
            }
        }
        return true;      
    }
};