Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
bool isPalindrome(Node *head)
{
    //Your code here
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second = reverse(slow);
    Node *first = head;
    while (second != NULL)
    {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }
    return true;
}