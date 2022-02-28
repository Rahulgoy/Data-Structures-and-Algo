int sum(Node *node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
    {
        return node->data;
    }
    return sum(node->left) + sum(node->right) + node->data;
}

bool isSumTree(Node *node)
{
    if (!node)
        return true;

    if (!node->left && !node->right)
    {
        return true;
    }
    return (node->data == sum(node->left) + sum(node->right) && isSumTree(node->left) && isSumTree(node->right));
}
