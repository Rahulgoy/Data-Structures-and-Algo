#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int data)
{
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct node *root, int data)
{
    struct node *temp;
    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = newnode(data);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = newnode(data);
            break;
        }
        else
            q.push(temp->right);
    }
}
void traversal(struct node *root)
{
    if (root == NULL)
        return;
    traversal(root->left);
    cout << root->data << " ";
    traversal(root->right);
}

int main()
{
    int nodes;
    cin >> nodes;
    int data;
    cin >> data;
    node *root = newnode(data);
    for (int i = 0; i < nodes - 1; i++)
    {
        int k;
        cin >> k;
        insert(root, k);
    }
    traversal(root);

    return 0;
}