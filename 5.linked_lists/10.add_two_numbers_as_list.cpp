Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // code here
    Node *list1 = reverse(first);
    Node *list2 = reverse(second);
    int carry = 0, sum = 0;
    Node *temp, *head, *newnode;
    temp = head = newnode = NULL;
    while (list1 != NULL || list2 != NULL)
    {
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        newnode = new Node(sum);
        if (head == NULL)
            head = newnode;
        else
            temp->next = newnode;
        temp = newnode;
        if (list1)
            list1 = list1->next;
        if (list2)
            list2 = list2->next;
    }
    if (carry > 0)
    {
        newnode = new Node(carry);
        temp->next = newnode;
        temp = newnode;
    }
    head = reverse(head);
    return head;
}