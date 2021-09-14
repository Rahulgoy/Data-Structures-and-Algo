int maxSum = 0;
int maxHeight = -1;
void solve(Node *root, int height, int sum)
{
    if (!root)
        return;
    sum += root->data;
    if (height >= maxHeight)
    {
        maxSum = max(sum, maxSum);
        maxHeight = height;
    }
    solve(root->left, height + 1, sum);
    solve(root->right, height + 1, sum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    //code here
    int height = -1;
    int sum = 0;
    solve(root, 0, 0);
    return maxSum;
}