//leetcode 814
//Binary tree pruning
//postorder traversal


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && root->left == NULL && root->right == NULL){
            root = NULL;
        }
        return root;
    }
};