vector<int> zigZagTraversal(Node *root)
{
    // Code here
    queue<Node *> q;
    vector<int> v;

    vector<vector<int>> vec;
    q.push(root);
    while (!q.empty())
    {
        vector<int> t;
        size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            t.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        vec.push_back(t);
    }
    for (int i = 0; i < vec.size())
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                v.push_back(vec[i][j]);
            }
        }
        else
        {
            reverse(vec[i].begin(), vec[i].end());
            for (int j = 0; j < vec[i].size(); j++)
            {
                v.push_back(vec[i][j]);
            }
        }
    }
    return v;
}