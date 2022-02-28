Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    unordered_map<int, int> m;
    Node *head = NULL, *temp, *newnode = NULL;
    Node *list1 = head1, *list2 = head2;
    while (list1 != NULL)
    {
        m[list1->data] = 1;
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        if (m[list2->data] == 1)
        {
            m[list2->data]++;
            newnode = new Node(list2->data);
            if (head == NULL)
            {
                head = newnode;
                temp = newnode;
            }
            else
                temp->next = newnode;
            temp = newnode;
        }
        list2 = list2->next;
    }
    return head;
}