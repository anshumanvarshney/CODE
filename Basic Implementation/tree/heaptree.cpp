#include<iostream>
using namespace std;

const int MAX=20;

class heap
{
	private:
		int a[MAX];
		int count;
	public:
		heap();
		void insert(int num);
		void makeheap();
		int add(int val);
		void display();
		void restoreup(int pos);
		void restoredown(int pos);
		int replace(int pos);
		int del();
};

heap::heap()
{
	int i;
	for(i=0;i<MAX;i++)
	{	
		a[i]=0;
	}
    count=0;
}

void heap::insert(int num)
{
	if(count<MAX)
	{
		a[count]=num;
		count++;
	}
	else
		cout<<"\nArray is Full";
}

void heap::makeheap()
{
	count--;  //because one extra space is created contain 0
	int i;
	for(i=count/2;i>=1;i--)  // count/2 having element one below leaf node 
	//i.e if leaf node having order 4 then element present in order 3
	{
		restoredown(i);
	}
}

int heap::add(int val)
{
	if(count<MAX)
	{
		count++;
		a[count]=val;
		restoreup(count);
		return 1;
	}
	else  // memory full
		return 0;
}

void heap::display()
{
	int i;
	for(i=1;i<=count;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void heap :: restoreup(int pos)
{
	int val=a[pos];  
	while(a[pos/2]<=val)// compare with root node
	{
		a[pos]=a[pos/2];
		pos=pos/2;
	}
	a[pos]=val;
}

void heap::restoredown(int pos)
{
	int val=a[pos];
	int i;
	while(pos<=count/2)
	{
		i=2*pos;
		if((i<count)&&(a[i]<a[i+1]))
			i++;
		if(val>=a[i])
			break;
		a[pos]=a[i];
		pos=i;
	}
	a[pos]=val;
	
}

int heap::replace(int pos) //pos contain data that is to be replace with root node
{
	int r=a[1];
	a[1]=pos;
	/*for(pos=count/2;pos>=1;pos--)
		restoredown(pos);*/
	//or
	restoredown(1);
	return r;
}

int heap::del()//delete of root node
{
	int val;
	val=a[1];
	a[1]=a[count]; // nth element store in 1st element
	count--;      // decrement a node
	restoredown(1);
	return val;
}

int main()
{
	heap h;
	int i;
	int ar[]={1000,7,10,25,17,23,27,16,19,37,42,4,33,1,5,11};//1000 is sentinal value
	int sz=sizeof(ar)/sizeof(int);
	for(i=0;i<sz;i++)
	{
		h.insert(ar[i]);
	}
	h.makeheap();
	cout<<"Heap :"<<"\n";
	h.display();
	i=24; //element that is to be added
	int result=h.add(i);
	if(result==0)//if array is full
		cout<<"cannot add element"<<"\n";
	else
	{
		cout<<"\nElement added :"<<i<<"\n";
		cout<<"\nHeap after addition of an element :"<<"\n";
		h.display();
	}
	i=h.replace(2);
	cout<<"\nElement replaced :"<<i<<"\n";
	cout<<"\nHeap after replacement of an element :"<<"\n";
	h.display();
	i=h.del();
	cout<<"\nElement deleted :"<<i<<"\n";
	cout<<"\nHeap after deletion of an element :"<<"\n";
	h.display();
}


/*
HEAP SORT
*/

/*
Complexity O(nlogn)
*/

#include<iostream>
using namespace std;

const int MAX=20;

class heap
{
	private:
		int a[MAX];
		int count;
	public:
		heap();
		void insert(int num);
		void makeheap();
		void display();
		void restoredown(int pos);
		void del();
};

heap::heap()
{
	int i;
	for(i=0;i<MAX;i++)
	{	
		a[i]=0;
	}
    count=0;
}

void heap::insert(int num)
{
	if(count<MAX)
	{
		a[count]=num;
		count++;
	}
	else
		cout<<"\nArray is Full";
}

void heap::makeheap()
{
	count--;
	int i;
	for(i=count/2;i>=1;i--)  // count/2 having element one below leaf node 
	//i.e if leaf node having order 4 then element present in order 3
	{
		restoredown(i);
	}
}

void heap::display()
{
	int i;
	for(i=1;i<=count;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void heap::restoredown(int pos)
{
	int val=a[pos];
	int i;
	while(pos<=count/2)
	{
		i=2*pos;
		if((i<count)&&(a[i]<a[i+1]))
			i++;
		if(val>=a[i])
			break;
		a[pos]=a[i];
		pos=i;
	}
	a[pos]=val;
	
}

void heap::del()//delete of root node
{
	int val,i,j;
	j=count;
	for(i=1;i<=j;i++)
	{
		val=a[1];
		a[1]=a[count]; // nth element store in 1st element
		a[count]=val;
		count--;
		restoredown(1);
	}
	count=j;
	for(i=1;i<=count;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	heap h;
	int i;
	int ar[]={1000,7,10,25,17,23,27,16,19,37,42,4,33,1,5,11};//1000 is sentinal value
	int sz=sizeof(ar)/sizeof(int);
	for(i=0;i<sz;i++)
	{
		h.insert(ar[i]);
	}
	h.makeheap();
	cout<<"Heap :"<<"\n";
	h.display();
    h.del();
}

/*
using while loop and display fn

#include<iostream>
using namespace std;

const int MAX=20;

class heap
{
	private:
		int a[MAX];
		int count;
	public:
		heap();
		void insert(int num);
		void makeheap();
		void restoredown(int);
		void display();
		void del();
};

heap::heap()
{
	count=0;
	int i;
	for(i=0;i<MAX;i++)
		a[i]=0;
}

void heap :: insert(int num)
{
	if(count<MAX)
	{
		a[count]=num;
		count++;
	}
	else cout<<"\nArray is full";
}

void heap::makeheap()
{
	count--;
	int i;
	for(i=count/2;i>=1;i--)
	{
		restoredown(i);
	}
}

void heap::restoredown(int pos)
{
	int i,val=a[pos];
	while(pos<=count/2)
	{
		i=2*pos;
		if(i<count&&a[i]<a[i+1])
			i++;
		if(val>=a[i])
			break;
		a[pos]=a[i];
		pos=i;
	}
	a[pos]=val;
}

void heap::display()
{
	int i;
	for(i=1;i<=count;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void heap :: del()
{
	int t,j,i=1;
	j=count;
	while(i<=j)
	{
		t=a[1];
		a[1]=a[count];
		a[count]=t;
		count--;
		restoredown(1);
		i++;
	}
	count=j;
}

int main()
{
	heap h;
	int ar[]={1000,7,10,25,17,23,27,16,19,37,42,4,33,1,5,11};
    int i,sz=sizeof(ar)/sizeof(int);
	for(i=0;i<sz;i++)
		h.insert(ar[i]);
	h.makeheap();
	h.display();
	h.del();
	h.display();
}
*/

