/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode *A)
{

    vector<vector<int>> v;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        vector<int> vec;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                vec.push_back(temp->val);
        }
        v.push_back(vec);
    }
    vector<int> res;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            res.push_back(v[i][j]);
        }
    }
    return res;
}
