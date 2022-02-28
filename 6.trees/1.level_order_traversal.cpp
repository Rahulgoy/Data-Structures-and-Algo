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
void level(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<struct node *> q;
    vector<int> v;

    q.push(root);
    while (!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
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

    level(root);
    return 0;
}

/* 
leetcode levelOrderTraversal
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root)
            return vec;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
                
            }
            vec.push_back(v);            
        }
        return vec;
    } */