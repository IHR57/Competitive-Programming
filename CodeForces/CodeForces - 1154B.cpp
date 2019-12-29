//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    for(int k = 0; k <= 500; k++){
        int temp = arr[0] + k;
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(arr[i] + k == temp || arr[i] - k == temp || arr[i] == temp){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<k<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;

    return 0;
}

