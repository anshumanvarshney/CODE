void reverse(Node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
 
void reverseUtil(Node *curr, Node *prev, Node **head)
{
    if (!curr->next)
    {
        *head = curr;
        curr->next = prev;
        return;
    }
 
    node *next = curr->next;
    curr->next = prev;
    reverseUtil(next, curr, head);
}