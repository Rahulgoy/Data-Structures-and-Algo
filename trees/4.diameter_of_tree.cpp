// Given a Binary Tree, find diameter of it.The diameter of a tree is the number of nodes on the longest path between two end nodes in
// the tree.The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded(note
// that there is more than one path in each tree of length nine, but no path longer than nine nodes).

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

int height(struct node *node)
{
    //code here
    int h = 0;
    if (!node)
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL)
        return 1;

    int left = height(node->left);
    int right = height(node->right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}
int diameter(struct node *node)
{
    int hei = height(node->left) + height(node->right) + 1;
    int leftd = diameter(node->left);
    int rightd = diameter(node->right);
    return max(hei, max(leftd, rightd));
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
    int dia = diameter(root);
    cout << dia;

    return 0;
}
