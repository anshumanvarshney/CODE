#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int array[10];
for(int i=0;i<5;i++)
{
 cout<<"\nEnter Element :";
 cin>>array[i];
}
int min=array[0];//for pos take pos =0 
int max=array[0];
for(i=0;i<5;i++){
    // finding minimum number in array
      if(min>array[i]){
	 min=array[i]; // take pos = i;
      }
      //finding maximum number in array
      if(max<array[i]){
      max=array[i];
      }
}

       // displaying output
	cout<<"Maximum Number is :"<<max<<endl;
	cout<<"Minimum Number is:"<<min<<endl;

getch();
return 0;
}

