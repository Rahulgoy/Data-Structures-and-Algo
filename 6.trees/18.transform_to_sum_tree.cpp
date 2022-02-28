int summation(Node *node)
{
    if (!node)
        return 0;
    int l = summation(node->left);
    int r = summation(node->right);
    int t = node->data;
    node->data = l + r;
    return t + l + r;
}

void toSumTree(Node *node)
{
    // Your code here
    // if(!node) return NULL;
    summation(node);
}