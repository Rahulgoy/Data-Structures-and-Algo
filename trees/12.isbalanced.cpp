int height(Node *root)
{
    if (!root)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if (root == NULL)
        return 1;
    if (abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    return false;
}