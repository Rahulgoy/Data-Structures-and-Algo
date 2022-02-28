int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

unordered_map<int, int> m;
int indx = 0;
Node *solve(int in[], int pre[], int start, int end)
{
    if (start > end)
        return NULL;
    int curr = pre[indx];
    indx++;
    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = m[curr];
    node->left = solve(in, pre, start, pos - 1);
    node->right = solve(in, pre, pos + 1, end);
}

Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    indx = 0;
    m.clear();
    for (int i = 0; i < n; i++)
        m[in[i]] = i;
    Node *root = solve(in, pre, 0, n - 1);
    return root;
}

// time complexity is o(n) because we have used maps if we use
// linear search to sort the left and right subtree then it would be o(n^2)