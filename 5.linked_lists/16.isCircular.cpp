bool isCircular(struct Node *head)
{
    //code here
    if (head == NULL)
        return true;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next == head)
            return true;
        temp = temp->next;
    }
    return false;
}