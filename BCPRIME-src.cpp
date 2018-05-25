#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
long ntotest(long n){
     long i;
     if (n<2)  return 0 ;
     for (i=2;i<=sqrt(n);i++) 
       if (n%i==0) return 0;
     return 1;
     }
int main()
{
     long n;
     cin>>n;
     if(ntotest(n)) cout<<"YES"; else cout<<"NO";
     getchar();
}
