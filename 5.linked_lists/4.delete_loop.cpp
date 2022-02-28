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

bool detectLoop(Node *head)
{
    // your code here
    unordered_map<Node *, int> m;
    while (head != NULL)
    {
        if (!m[head])
        {
            m[head] = 1;
            head = head->next;
        }
        else
            return true;
    }
    // Floyd’s Cycle-Finding Algorithm.
    // Node *slow=head->next;
    // Node *fast=head->next->next;
    // while(fast && slow && fast->next){
    //     slow=slow->next;
    //     fast=fast->next->next;
    //     if(fast==slow) return true;
    // }

    return false;
}
void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *slow, *fast;
    slow = head;
    unordered_map<Node *, int> m;
    m[slow] = 1;
    while (slow != NULL)
    {
        if (!m[slow->next])
        {
            m[slow] = 1;
            slow = slow->next;
        }
        else
        {
            slow->next = NULL;
        }
    }
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
    int res = detectLoop(head);
    if (res == 1)
        cout << "True";
    else
        cout << "False";
    return 0;
}
