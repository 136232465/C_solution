//leetcode 310
//minimum height trees

class Solution {
public:
        struct Node{
        set<int> neighbor;
        bool isLeaf() const{
            return neighbor.size()==1;
        }
    };
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
         vector<int> resbuf;
         vector<int> res;
         vector<Node> nodes(n);
         if (n == 1)
			{
				resbuf.push_back(0);
				return resbuf;
			}
			if (n == 2)
			{
				resbuf.push_back(0);
				resbuf.push_back(1);
				return resbuf;
			}
         for (auto p : edges){
             nodes[p.first].neighbor.insert(p.second);
             nodes[p.second].neighbor.insert(p.first);
         }
         for (int i=0; i < n; ++i){
             if(nodes[i].isLeaf()){
                 resbuf.push_back(i);
             }
         }
        while(1){
         for (auto m : resbuf){
             for (auto n: nodes[m].neighbor){
                 nodes[n].neighbor.erase(m);
                 if(nodes[n].isLeaf()){
                     res.push_back(n);
                 }
             }
         }
         if (res.empty()){
             return resbuf;
         }
         resbuf.clear();
         for(int i = 0; i < res.size(); ++i){
             resbuf.push_back(res[i]);
         }
         res.clear();
    }
}

};//逐层剔除最底层结点