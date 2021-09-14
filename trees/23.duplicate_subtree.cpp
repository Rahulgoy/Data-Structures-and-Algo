unordered_map<string, int> m;
string solve(Node *root)
{
    if (!root)
        return "$";
    string s = "";
    if (!root->left && !root->right)
    {
        s = to_string(root->data);
        return s;
    }
    s += to_string(root->data);
    s += solve(root->left);
    s += solve(root->right);
    m[s]++;
    return s;
}

int dupSub(Node *root)
{
    // code here
    m.clear();

    if (!root)
        return 0;
    string s = solve(root);

    for (auto x : m)
    {
        if (x.second >= 2)
            return 1;
    }
    return 0;
}