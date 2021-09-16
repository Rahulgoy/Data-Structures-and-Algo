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

Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *currnode, *nextnode;
    currnode = nextnode = head;
    if (currnode == NULL)
        return head;
    while (currnode->next != NULL)
    {
        if (currnode->data == currnode->next->data)
        {
            nextnode = currnode->next->next;
            free(currnode->next);
            currnode->next = nextnode;
        }
        else
        {
            currnode = currnode->next;
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
    addnode(20);
    addnode(20);
    addnode(25);

    display(head);
    head = removeDuplicates(head);
    display(head);
    return 0;
}
