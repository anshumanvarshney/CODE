ListNode* Solution::rotateRight(ListNode* head, int d)
{   
    ListNode* curr = head,*res = head,*last;  
    int size = 0;
    
    if(d == 0 || head == NULL)
	{
        return head;
    }
    
    while(curr != NULL)
	{
        last = curr;
        curr = curr->next;
        size++;
    }
    
    while(d >= size)//if it is possible
	{
        d = d - size;
    }
    
    d = size - d;
    //or simple d (depend on right rotation or left rotation)
    last->next =res;
    // now, its a circular list
    
    curr = head;
    
    while(d != 0)
	{
        last = curr;
        curr = curr->next;
        d--;
    }
    
    res = curr;
    last->next = NULL;
    
    return res;
}
