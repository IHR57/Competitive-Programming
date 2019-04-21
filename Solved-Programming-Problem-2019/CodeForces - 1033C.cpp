#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int arr[MAX], pos[MAX], res[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        pos[arr[i]] = i;
    }

    for(int i = n; i > 0; i--){
        int k = pos[i];
        bool possible = false;
        for(int j = k + i; j <= n; j += i){
            if(arr[j] > i && res[j] == 0){
                possible = true;
                break;
            }
        }
        for(int j = k - i; j >= 1; j -= i){
            if(arr[j] > i && res[j] == 0){
                possible = true;
                break;
            }
        }
        if(possible)    res[k] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(res[i])
            cout<<"A";
        else
            cout<<"B";
    }
    cout<<endl;

    return 0;
}
