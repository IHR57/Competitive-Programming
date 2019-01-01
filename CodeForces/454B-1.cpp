#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, arr[MAX], b[MAX], temp[MAX], c[MAX], count = 1;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        b[i] = arr[i];
    }

    sort(b, b + n);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == arr[i]){
            cnt++;
        }
    }

    if(cnt == n){
        cout<<0<<endl;
        return 0;
    }

    int k = n - 2, j = 1;

    temp[0] = arr[n-1];
    while(arr[k] <= arr[k + 1] && k >=  0){
        temp[j++] = arr[k];
        count++;
        k--;
    }

    int l = 0;
    for(int i = j - 1; i >= 0; i--){
        c[l++] = temp[i];
    }
    for(int i = 0; i < n - count; i++){
        c[l++] = arr[i];
    }

    for(int i = 0; i < n; i++){
        if(b[i] != c[i]){
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<count<<endl;

    return 0;
}
