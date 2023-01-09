void preorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(!root) return res;
        // Recursive         
        // preorder(root,res);
        // return res;
        
        
        // Iterative
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *temp=st.top();
            st.pop();
            if(temp){
                res.push_back(temp->val);
            
                if(temp->right) st.push(temp->right);
                if(temp->left) st.push(temp->left);
            }
            
        }
        return res;
    }