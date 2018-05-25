#include<iostream>
using namespace std;
#define FOR(z,x,y) for (int z=x;z<=y;z++)
#define maxn 1005

int a[maxn][maxn],m,n;
int d1[maxn],c1[maxn],d2[maxn],c2[maxn];
long long kq=0;

void Solve()
{
    FOR(i,0,m+1)
    {
        d1[i]=0;
        d2[i]=0;
    }
    FOR(j,0,n+1)
    {
        c1[j]=0;
        c2[j]=0;
    }
    FOR(i,1,m)
        FOR(j,1,n)
        {
            if (a[i][j]==1)
            {
                d1[i]++;
                c1[j]++;
            }
            else if (a[i][j]==2)
            {
                d2[i]++;
                c2[j]++;
            }
        }
    /*FOR(i,1,m)
    {
        cout<<d1[i]<<" ";
    }
    cout<<endl<<endl;
    FOR(i,1,m)
    {
        cout<<d2[i]<<" ";
    }
    cout<<endl<<endl;
    FOR(j,1,n)
    {
        cout<<c1[j]<<" ";
    }
    cout<<endl<<endl;
    FOR(j,1,n)
    {
        cout<<c2[j]<<" ";
    }*/

    kq=0;
    FOR(i,1,m)
        FOR(j,1,n)
            if (a[i][j]==0) continue;
            else if (a[i][j]==1)
            {
                kq+=d2[i]*c2[j];
            }
            else
            {
                kq+=d1[i]*c1[j];
            }
}

void inkq()
{
    cout<<kq<<endl;
}

int main()
{
    int t;
    cin>>t;
    FOR(u,1,t)
    {
        cin>>m>>n;
        char c;
        FOR(i,1,m)
        {
            FOR(j,1,n)
            {
                cin>>c;
                a[i][j]=c-'0';
            }
        }
        Solve();
        inkq();
    }
}
