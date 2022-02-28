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
void Preordertraversal(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preordertraversal(root->left);
    Preordertraversal(root->right);
}
void IterativePreorderTraversal(struct node *root)
{
    vector<int> v;
    stack<struct node *> st;

    if (!root)
    {
        return;
    }
    st.push(root);

    while (!st.empty())
    {
        struct node *curr = st.top();
        st.pop();
        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
        if (curr->right != NULL)
        {
            st.push(curr->right);
        }
    }
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
    IterativePreorderTraversal(root);
    cout << endl
         << "Non Iterative:" << endl;
    Preordertraversal(root);

    return 0;
}