int HasCycle(Node head)
{
    if (head == Null){
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != null && fast->next != null)
	{
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            return 1;
        }
    }

    return 0;
}
/*
Note :
To detect start of loop
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 4
after checking i.e if loop is there :
s is pointing to first node and keep f as it is
then s=s->next and f= f->next 
if(f==s) at any node then the node is the start of the loop 

do it by drawing ll
*/
/*

int HasCycle(Node head)
{
    if (head == Null){
        return 0;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != null && fast->next != null)
	{
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            cout<<"Loop has cycle";
			slow =head;
			while (fast != null && fast->next != null)
			{
				slow =slow ->next;
				fast=fast->next;
				if(slow==fast)
				{
					cout<<slow <<"is the start of the loop"
				}
			}
        }
    }

    return 0;
}

*/