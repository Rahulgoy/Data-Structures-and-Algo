vector<int> topView(Node *root)
{
    map<int, int> m;
    vector<int> v;
    int hd = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if (!m[h])
        {
            m[h] = temp->data;
        }
        if (temp->left != NULL)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, h + 1});
        }
    }
    for (auto x : m)
    {
        v.push_back(x.second);
    }

    return v;
}