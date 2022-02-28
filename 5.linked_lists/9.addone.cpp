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

Node *reverse(Node *head)
{
    Node *prevnode = NULL;
    Node *currnode, *nextnode;
    currnode = nextnode = head;

    while (currnode != NULL)
    {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
    return head;
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    if (!head)
        return head;
    head = reverse(head);
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL && temp->data == 9)
        {
            temp->data = 1;
            Node *tmp = new Node;
            tmp->data = 0;
            tmp->next = head;
            head = tmp;
            temp = temp->next;
        }
        else if (temp->data == 9)
        {
            temp->data = 0;
            temp = temp->next;
        }
        else
        {
            temp->data++;
            break;
        }
    }
    head = reverse(head);
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
    addnode(55);
    display(head);
    head = addOne(head);
    display(head);
    return 0;
}
