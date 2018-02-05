/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example: Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
*/


LinkedListNode* reverseSublist(LinkedListNode* head, int m, int n)
{
            LinkedListNode* newHead = newNode(-1);
	        newHead->next = head;
	        LinkedListNode* prev = newHead;
	        for(int i = 0 ; i < m-1 ; i++){
	            prev = prev->next;
	        }
	        LinkedListNode* reversedPrev = prev;
	        //position m
	        prev = prev->next;
	        LinkedListNode* cur = prev->next;
	        for(int i = m ; i < n ; i++){
	            prev->next = cur->next;
	            cur->next = reversedPrev->next;
	            reversedPrev->next = cur;
	            cur = prev->next;
	        }
	        return newHead->next;
}

or implement yours
