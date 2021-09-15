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

Node *reverse(Node *head, int k)
{
    // Complete this method
    Node *nextnode = head;
    Node *currnode = head;
    Node *prevnode = NULL;
    int size = k;
    while (size-- && currnode != NULL)
    {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    if (head != NULL)
    {
        head->next = reverse(nextnode, k);
    }
    return prevnode;
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
    addnode(20);
    addnode(25);
    addnode(53);
    addnode(27);
    addnode(35);
    display(head);
    Node *res = reverse(head, 4);
    display(res);
    return 0;
}