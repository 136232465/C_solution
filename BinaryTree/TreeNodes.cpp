//leetcode 222
//Count complete tree Nodes
//O(log(n)²)  time


class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h == 0){
            return 0;
        }
        if (height(root->right) == h-1){
            return countNodes(root->right) + pow(2,h-1);
        } else {           
            return countNodes(root->left) + pow(2,h-2);
        }
    }
private:
    int height(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        return 1+height(root->left);
    }
};