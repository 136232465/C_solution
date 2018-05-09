//非递归前序遍历

vector<int>  preorderTraversal(TreeNode *root, )
{
	vector<int> res;
	if (root== NULL){
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

//非递归中序遍历

vector<int> inorderTraversal(TreeNode* root){
	vector<int> res;
	if(root == NULL){
		return res;
	}
	stack<TreeNode*> s;
	TreeNode* p = root;
	while(p != NULL || s.empty()){
		while(p!=NULL){
			s.push(p);
			p = p->left;
		}
		if(!s.empty()){
			p = s.top();
			res.push_back(p->val);
			s.pop();
			p = p->right;
		}
	}	
}

//非递归后序遍历
vector<int> postorderTraversal(TreeNode* root){
		vector<int> res;
	if (root== NULL){
		return res;
	}
    stack<TreeNode*> s;
	TreeNode* p = root;
	while(p!= NULL || !s.empty()){
		while(p!= NULL){
			res.push_back(p->val);
			s.push(p);
			p = p->right;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->left;
		}
	}
	reverse(res.begin(),res.end());
	return res;
}

