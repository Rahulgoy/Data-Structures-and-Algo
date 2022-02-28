int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    unordered_map<Node *, int> m;
    Node *list1 = head1, *list2 = head2;

    while (list1 != NULL)
    {
        m[list1] = 1;
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        if (m[list2])
        {
            return list2->data;
        }
        list2 = list2->next;
    }
}
