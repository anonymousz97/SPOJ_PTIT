#include <stdio.h>
long gcd(long a,long b){
  if(b==0)return a;
  else return gcd(b, a%b);
}
long lcm(long a,long b){
  return (a*b)/gcd(a,b);
}
int main(){
  int T,a,b,i;
  long long ma,aa,bb,ans;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&a,&b);
    ma=lcm(a-1, b-1);
    aa=ma/(a-1);
    bb=ma/(b-1);
    ans=1+ma-((aa-1)*(bb-1))/2;
    printf("%lld\n",ans);
  }
  return 0;
}