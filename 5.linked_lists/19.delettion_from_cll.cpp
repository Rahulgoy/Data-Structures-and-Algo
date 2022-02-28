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
    temp->next = head;
    if (head != NULL)
    {
        Node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    else
    {

        temp->next = temp;
    }
    head = temp;
}

void display(Node *node)
{
    Node *ptr;
    ptr = node;
    while (ptr != node)
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

    return 0;
}
