// 331
// verify preorder serialization of a binary tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()){
            return false;
        }
        preorder += ',';
        int n = preorder.size();
        int diff = 1;
        for (int i = 0; i < n; ++i){
            if(--diff < 0 )return false;
            if(preorder[i] != '#') diff += 2;
            while(preorder[i] != ',')++i;
        }
        return diff == 0;        
    }
};