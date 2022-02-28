#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void addnode(int data)
{
    Node *temp = new Node;

    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

Node *removeDuplicatesfromUnsorted(Node *head)
{
    // your code goes here
    unordered_map<int, int> m;
    Node *temp = head;
    m[head->data] = 1;
    while (temp->next != NULL)
    {
        if (!m[temp->next->data])
        {
            m[temp->next->data] = 1;
            temp = temp->next;
        }
        else
        {
            Node *nextnode;
            if (temp->next->next == NULL)
                nextnode = NULL;
            else
                nextnode = temp->next->next;

            free(temp->next);
            temp->next = nextnode;
        }
    }
    return head;
}
void display(Node *node)
{
    Node *ptr;
    ptr = node;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}
int main()
{
    addnode(5);
    addnode(10);
    addnode(35);
    addnode(15);
    addnode(15);
    addnode(20);
    addnode(20);
    addnode(25);
    addnode(5);
    display(head);
    head = removeDuplicatesfromUnsorted(head);
    display(head);
    return 0;
}
