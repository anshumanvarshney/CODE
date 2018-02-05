/*
Intersection of two sorted Linked lists

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. 
The new list should be made with its own memory — the original lists should not be changed.

For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8,
 then your function should create a third list as 2->4->6.
 */
 
 /*
 Note : in case of unsorted list and output require order then sort the list first and 
 do the same as we did in sorted list .
 reverse if neccessary based on output

if order is not important than 
Intersection (list1, list2)
Initialize result list as NULL. Traverse list1 and look for its each element in list2,
 if the element is present in list2, then push at beginning the element to result. 

 */
 
 /*
 for union
Union (list1, list2):
Initialize result list as NULL. Traverse list1 and push at beg all of its elements to the result.
Traverse list2. If an element of list2 is already present in result then do not insert it to result, otherwise insert.

but in this case
 Input:
9
1 5 9 9 5 1 3 5 7
9
3 5 7 1 5 9 9 5 1

Its Correct output is:
1 3 5 7 9

And Your Output is:
1 1 3 5 5 5 7 9 9
 
then make a another function for deleting duplicate
and return the node 
 */
 
 /*
if a pointer node is 
node *temp
and function prototype is **temp  then we have to pass &temp;
if a pointer node is 
node **temp
and function prototype is **temp  then we have to pass temp;
*/

void push(node **head,int data)
{
	
}
 
void intersection(node **a,node **b,node **c)
{
	if(*a==NULL || *b==NULL)
		*c=NULL;
	while(*a!=NULL && *b!=NULL)
	{
		if((*a)->data==(*b)->data)
		{
			push(c,(*a)->data)
			(*a)=(*a)->next;
			(*b)=(*b)->next
		}
		else if((*a)->data > (*b)->data)
				(*b)=(*b)->next
		else 	(*a)=(*a)->next;
	}
}

//for union
/*
while(i<n&&j<m)
{
	if(a[i]<a[j])
		push(a[i++]);
	else if(a[i]>a[j])
		push(a[j++])
	else
	{
		push(a[i])
		i++;
		j++
	}
}
*/

node *union(node *ac,node *bc)
{
	node *c=NULL;
	node *a=ac;
	node *b=bc;
	while(a!=NULL)
	{
		push(&c,a->data)
		a=a->next;
	}
	node *ca=c;
	int flag=0;
	while(b!=NULL)
	{
		while(ca!=NULL)
		{
			if(b->data==ca->data)
				flag=1;
			ca=ca->next;
		}
		if(flag==0)
			push(&c,b->data);
		ca=c;
		b=b->next;
	}
	//if required
	node *cs=sort(c);
	node *d =deleteduplicate(cs);
	return d;
}