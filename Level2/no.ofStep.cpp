/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb 
either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter). 
Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same. so output =3;

cout<<(n+2)/2 i.e for 5 {1 2 2,  2 1 2, 2 2 1}

it is the another version of no. of step problem 
i.e if  1 2 3 4.... step allowed 
the generealised version is a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4]...........

*/