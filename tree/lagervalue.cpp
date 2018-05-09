//leetcode 515     find largest Values in Each Tree Row
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL){
            return res;
        }
        deque<TreeNode*> s;
        s.push_back(root);
        while(!s.empty()){
            int n = s.size();
            int maxnum = INT_MIN;
            while(n--){
                TreeNode* temp = s.front();
                s.pop_front();
                if(temp->left != NULL){
                    s.push_back(temp->left);
                }
                if(temp->right != NULL){
                    s.push_back(temp->right);
                }
                maxnum = max(maxnum,temp->val);
            }
            res.push_back(maxnum);
        }
        return res;
    }
};