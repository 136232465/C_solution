//非递归前序遍历

vector<int>  preorderTraversal(TreeNode *root, )
{
	vector<int> res;
	if (root.empty()){
		return res;
	}
    stack<TreeNode> s;
	TreeNode* p = root;
	while(p!= NULL || !s.empty()){
		while(p!= NULL){
			res.push_back(p->val);
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	return res;
}