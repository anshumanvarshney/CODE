/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

int count(ListNode* head)
{
    ListNode* temp=head;
    int c=0;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
 
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
        int len=count(head);
        ListNode *cur = head, *prev = head;
        if(len<n)//if length is less than n than delete first element (given in ques)
        {
            head=head->next;
            return head;
        }
        while(n > 0)
        {
            cur = cur->next;
            n--;
        }
        if (cur == NULL) 
            return head->next;
        while (cur->next != NULL)
        {
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;   
}