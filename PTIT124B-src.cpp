#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int main()
{
    int n,k=0;
    cin >> n;
    while(n--)
    {
        k++;
        char str[20][20],str1[441],str2[441];
        int r,c,count=0;
        cin >> r >> c;
        //nhap ma tran
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> str[i][j];
        //xu ly ma tran xoay oc
        //chuyen cac ki tu dang xoay oc vao 1 xau khac
        int gt=0,t=0,d=r-1,e=c-1;
        while(gt<r*c)
        {
            for(int i=t;i<=e;i++)  //duyet tu trai sang phai
            {
                str1[gt]=str[t][i];
                gt++;
            }
            for(int i=t+1;i<=d;i++) //tu tren xuong duoi
            {
                str1[gt]=str[i][e];
                gt++;
            }
            for(int i=e-1;i>=t;i--)  //tu phai sang trai
            {
                str1[gt]=str[d][i];
                gt++;
            }
            for(int i=d-1;i>t;i--)  //duoi len tren
            {
                str1[gt]=str[i][t];
                gt++;
            }
            t++;d--;e--;  //thu nho ma tran
        }
            //xu ly chuyen 5 bit thanh so tuong ung
            for(int i=0;i<r*c;i++)
            {
                int f=0;
                int o=4;
                if((4+i)>r*c-1)  break;
                for(int j=i;j<=i+4;j++)
                {
                    f+=(str1[j]-'0')*pow(2,o);
                    o--;
                }
                if(f==0) str2[count]=32;  //neu f=0 thi cho thanh ki tu khoang trang
                else if(f>0)
                    str2[count]=f+64;
                i+=4;
                count++;
            }
          cout << k << " ";
          for(int i=0;i<count;i++)
            cout << str2[i];
          cout << endl;

    }
}