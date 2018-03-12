//leetcode 606
// time O(n);
// You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
// Input: Binary tree: [1,2,3,4]
// Output: "1(2(4))(3)"
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string s = to_string(t->val);
        if (t->left)  s += "(" + tree2str(t->left) + ")";
        else if (t->right) s += "()";
        if (t->right) s += "(" + tree2str(t->right) + ")";
        return s;
    }
};