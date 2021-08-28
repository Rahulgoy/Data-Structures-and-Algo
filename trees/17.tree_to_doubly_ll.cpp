void helper(Node *&head, Node *&prev, Node *root, int &f)
{
    if (!root)
        return;
    helper(head, prev, root->left, f);
    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    helper(head, prev, root->right, f);
}

Node *bToDLL(Node *root)
{
    // your code here
    Node *head = NULL;
    Node *prev = NULL;
    int f = 0;
    helper(head, prev, root, f);
    return head;
}

// here left and right are same as next and prev we used to create while construction of linked lists