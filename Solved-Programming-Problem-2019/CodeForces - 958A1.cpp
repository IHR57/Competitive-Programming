//Problem ID: CodeForces - 958A1 (Death Stars)
//Programmer: IQBAL HOSSAIN        Description: Implementation
//Date: 28/04/19
#include <bits/stdc++.h>
#define MAX 15
using namespace std;

char a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int n;

bool Equal()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

void rotateA()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[j][n-i-1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = c[i][j];
        }
    }
}

void flip()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][n-j-1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = c[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>b[i][j];
        }
    }

    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    flip();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }
    rotateA();
    if(Equal()){
        cout<<"Yes"<<endl;
        return 0;
    }

    cout<<"No"<<endl;

    return 0;
}
