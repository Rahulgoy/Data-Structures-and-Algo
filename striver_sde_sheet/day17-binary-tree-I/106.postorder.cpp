/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        
        
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(!root) return res;
        // Recursive         
        // postorder(root,res);
        // return res;
        
        
        // Iterative
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, int> vis;
        while(!st.empty()){
            TreeNode *temp=st.top();
            cout<<temp->val<<" ";
            vis[temp]=1;
            if(temp){
                if(temp->left){
                    if(!vis[temp->left]) {st.push(temp->left);continue;}
                } 
                if(temp->right){
                    if(!vis[temp->right]) {st.push(temp->right);continue;}
                } 
                
                res.push_back(st.top()->val);
            }
            st.pop();
            
        }
        return res;
    }
    
};