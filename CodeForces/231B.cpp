#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[MAX], n, d, l;

    cin>>n>>d>>l;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0)
            arr[i] = 1;
        else
            arr[i] = l;
    }

    while(1){
        int cnt = 0, sum = 0, c = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                sum += arr[i];
            else
                sum -= arr[i];
        }
        if(sum == d){
            for(int j = 0; j < n; j++){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
            return 0;
        }
        for(int i = 0; i < n; i++)
            if(arr[i] == l)
                cnt++;
        if(cnt == n)
            break;
        for(int i = 0; i < n; i++){
            if(arr[i] < l && !c)
                arr[i]++, c++;
        }
    }

    for(int i = 0; i < n; i++){
        if(i % 2 == 0)
            arr[i] = l;
        else
            arr[i] = 1;
    }

    while(1){
        int cnt = 0, sum = 0, c = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                sum += arr[i];
            else
                sum -= arr[i];
        }
        if(sum == d){
            for(int j = 0; j < n; j++){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
            return 0;
        }
        for(int i = 0; i < n; i++)
            if(arr[i] == l)
                cnt++;
        if(cnt == n)
            break;

        for(int i = 0; i < n; i++){
            if(arr[i] < l && !c)
                arr[i]++, c++;
        }
    }

    cout<<-1<<endl;

    return 0;
}
