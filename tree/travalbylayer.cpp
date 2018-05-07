//leetcode 102 Binary Tree Level Order Traversal
//use queue;



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL){
            return res;
        }
        deque<TreeNode*> visited;
        visited.push_back(root);
        while(!visited.empty()){
            int n = visited.size();
            vector<int> ivec;
            while(n--){
                TreeNode* temp = visited.front();
                visited.pop_front();
                if(temp->left != NULL){
                    visited.push_back(temp->left);
                }
                if (temp->right != NULL){
                    visited.push_back(temp->right);
                }
                ivec.push_back(temp->val);
            }
            res.push_back(ivec);
        }
        return res;
    }
};