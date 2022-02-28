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
Node *start_node_of_loop(Node *head)
{
    unordered_map<Node *, int> m;
    Node *temp = head;
    Node *loop;
    m[temp] = 1;
    while (temp != NULL)
    {
        if (!m[temp->next])
        {
            m[temp->next] = 1;
            temp = temp->next;
        }
        else
        {
            loop = loop->next;
            break;
        }
    }
    return loop;
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

    display(head);
    // reverse_iter();
    // display(head);
    Node *rest = reverse_rec(head);
    head = rest;
    display(rest);
    return 0;
}