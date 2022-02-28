Node *middleNodem1(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    if (count % 2 == 0)
    {
        count = count / 2 + 1;
    }
    else
    {
        count = (count + 1) / 2;
    }
    for (int i = 0; i < count - 1; i++)
    {
        temp = temp->next;
    }
    return temp;
}
Node *middleNodem2(Node *head)
{
    struct Node *fast, *slow;
    fast = slow = head;
    if (head == NULL)
        exit(0);
    else
    {
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow;
}