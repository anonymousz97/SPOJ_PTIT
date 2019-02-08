#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int a[100000];
int b[100000];
int c[100000];

int roadmap[100000];
int position[100000];
int turn[1000000];
int n;
int pos = 0;
//black space = 0 ,empty space = 1,white space = 2
void init(int n){
    for(int i=0;i<n;i++){
        a[i]=0;
        b[i]=2;
        c[i]=0;
    }
    a[n]=1;
    c[n]=1;
    b[n]=1;
    for(int i=n+1;i<2*n+1;i++){
        a[i]=2;
        b[i]=0;
        c[i]=2;
    }
    //copy(begin(a),end(a),begin(c));
}

bool result(int a[]){
    for(int i=0;i<2*n+1;i++){
        if(a[i]!=b[i])  return false;
    }
    return true;
}

bool canMove(int a[],int n){
    if(a[n]==0){
        if(a[n+1]==1){
            return true;
        }
        else{
            if(a[n+1]==2 && a[n+2]==1){
                return true;
            }
        }
    }
    else{
        if(a[n-1]==1){
            return true;
        }
        else{
            if(a[n-1]==0 && a[n-2]==1){
                return true;
            }
        }
    }
    return false;
}
bool checkMove(int a[]){
    for(int i=0;i<2*n+1;i++){
        if(a[i]==1) continue;
        if(canMove(a,i)==true){
            return true;
        }
    }
    return false;
}
void printRoadMap(){
    for(int i=0;i<pos;i++){
        if(roadmap[i]==0){
            if(turn[i]==0){
                cout<<"Black at position "<<position[i]<<" turn right"<<endl;
            }
            else
            {
                cout<<"Black at position "<<position[i]<<" jump right"<<endl;
            }
        }
        else{
            if(turn[i]==0){
                cout<<"White at position "<<position[i]<<" turn left"<<endl;
            }
            else
            {
                cout<<"White at position "<<position[i]<<" jump left"<<endl;
            }
        }
    }
}

bool solve(int a[]){
    if(checkMove(a)==false){
        if(result(a)==true){
            printRoadMap();
            pos=0;
            return true;
        }
        return false;
    }
    else{
        //generate all possible moves (maximum 4 possible moves) and recursive solve(int a[after-swap])
        for(int i=0;i<2*n+1;i++){
            if(a[i]==1) continue;
            if(a[i]==0){
                if(a[i+1]==1){
                    int temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                    roadmap[pos]=0;
                    position[pos]=i;
                    turn[pos]=0;
                    pos++;
                    solve(a);
                    pos--;
                    // if(solve(a)){
                    //     cout<<"Black at position "<<i<<" go right"<<endl;
                    // }
                    temp=a[i+1];
                    a[i+1]=a[i];
                    a[i]=temp;
                }
                else{
                    if(a[i+1]==2 && a[i+2]==1){
                        int temp=a[i];
                        a[i]=a[i+2];
                        a[i+2]=temp;
                        roadmap[pos]=0;
                        position[pos]=i;
                        turn[pos]=1;
                        pos++;
                        solve(a);
                        pos--;
                        // if(solve(a)){
                        //     cout<<"Black at position "<<i<<" jump right"<<endl;
                        // }
                        temp=a[i+2];
                        a[i+2]=a[i];
                        a[i]=temp;
                    }
                }
            }
            else{
                if(a[i-1]==1){
                    int temp=a[i];
                    a[i]=a[i-1];
                    a[i-1]=temp;
                    roadmap[pos]=2;
                    position[pos]=i;
                    turn[pos]=0;
                    pos++;
                    solve(a);
                    pos--;
                    // if(solve(a)){
                    //     cout<<"White at position "<<i<<" go left"<<endl;
                    // }
                    temp=a[i-1];
                    a[i-1]=a[i];
                    a[i]=temp;
                }
                else{
                    if(a[i-1]==0 && a[i-2]==1){
                        int temp=a[i];
                        a[i]=a[i-2];
                        a[i-2]=temp;
                        roadmap[pos]=2;
                        position[pos]=i;
                        turn[pos]=1;
                        pos++;
                        solve(a);
                        pos--;
                        // if(solve(a)){
                        //     cout<<"White at position "<<i<<" jump left"<<endl;
                        // }
                        temp=a[i-2];
                        a[i-2]=a[i];
                        a[i]=temp;
                    }
                }
            }
        }
        //swap again
    }
}


main(){
    cout<<"Input n : ";
    cin>>n;
    init(n);
    for(int i=0;i<2*n+1;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    if(solve(a)){
        cout<<"Problem solved"<<endl;
    }
    else
    {
        cout<<"Problem cant solved"<<endl;
    }
    
}