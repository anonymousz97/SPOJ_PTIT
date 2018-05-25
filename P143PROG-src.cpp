#include<iostream> 
using namespace std; 
long n,k; 
main() 
{ 
cin>>n; 
cin>>k; 
if(k%(n-1)==0) 
cout<< (n*(k/(n-1))-1)<<" "<<n*(k/(n-1)); 
else 
cout<< k+(k/(n-1))<< " "<<k+(k/(n-1));	
} 