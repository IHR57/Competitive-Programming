//Problem ID: CodeForces - 1031B (Curiosity has no limits)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 16/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX], b[MAX], t[MAX];
int n;

int solve(int x)
{
    t[1] = x;
    for(int i = 2; i <= n; i++){
        bool flag = false;
        for(int j = 0; j <= 3; j++){
            if(((t[i-1] | j) == a[i-1]) && ((t[i-1] & j) == b[i-1])){
                t[i] = j;
                flag = true;
                break;
            }
        }
        if(!flag){
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;

    for(int i = 1; i < n; i++){
        cin>>a[i];
    }
    for(int i = 1; i < n; i++)
        cin>>b[i];

    for(int i = 0; i <= 3; i++){
        if(solve(i)){
            cout<<"YES"<<endl;
            for(int i = 1; i <= n; i++){
                cout<<t[i]<<" ";
            }
            cout<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
