// my own approach
vector<vector<Node *>> levelOrder(Node *root)
{

    vector<vector<Node *>> v;
    if (!root)
        return v;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<Node *> vec;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            vec.push_back(temp);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        v.push_back(vec);
    }
    return v;
}

bool check(Node *root)
{
    //Your code here
    vector<int> final;
    vector<vector<Node *>> res = levelOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            if (!res[i][j]->left && !res[i][j]->right)
                final.push_back(i);
        }
    }
    vector<int>::iterator ip;
    // remove all duplicate values
    ip = std::unique(final.begin(), final.end());
    // resize vector after removing duplicate values
    final.resize(distance(final.begin(), ip));

    if (final.size() != 1)
        return false;
    return true;
}

//  another approach

int ans;
void solve(Node *root, int height, int &ma)
{
    if (!root)
        return;
    if (ans == 0)
        return;
    if (!root->left && !root->right)
    {
        if (ma == -1)
        {
            ma = height;
        }
        else if (height != ma)
        {
            ans = 0;
        }
        return;
    }
    solve(root->left, h + 1, ma);
    solve(root->right, h + 1, ma);
}
bool check(Node *root)
{
    ans = 1;
    int height = 0;
    int ma = -1;
    solve(root, height, ma);
    return ans;
}