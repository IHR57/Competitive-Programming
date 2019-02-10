//Problem ID: CodeForces - 1081B (Farewell Party)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 10/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int counter[MAX], b[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        counter[n-arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(counter[n-arr[i]] % (n-arr[i]) != 0){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }

    cout<<"Possible"<<endl;

    int idx = 1;
    for(int i = 0; i < n; i++){
        if(counter[n - arr[i]] % (n - arr[i]) == 0){
            b[n - arr[i]] = idx++;
        }
        counter[n - arr[i]]--;
        cout<<b[n - arr[i]]<<" ";
    }
    cout<<endl;

    return 0;
}
