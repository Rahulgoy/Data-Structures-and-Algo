vector<int> bottomView(Node *root)
{
    map<int, int> m;
    queue<pair<Node *, int>> q;
    vector<int> v;

    q.push({root, 0});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();

        m[h] = (temp->data);
        if (temp->left)
            q.push({temp->left, h - 1});
        if (temp->right)
            q.push({temp->right, h + 1});
    }

    for (auto x : m)
    {
        v.push_back(x.second);
    }
    return v;
}