//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[MAX], n;
    priority_queue<int> pq1, pq2;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] % 2 == 0){
            pq1.push(arr[i]);
        }
        else
            pq2.push(arr[i]);
    }

    int Min = min(pq1.size(), pq2.size());

    int ans = 0;
    for(int i = 0; i < Min; i++){
        pq1.pop();
        pq2.pop();
    }

    if(!pq1.empty())
        pq1.pop();
    if(!pq2.empty())
        pq2.pop();

    while(!pq1.empty()){
        ans += pq1.top();
        pq1.pop();
    }
    while(!pq2.empty()){
        ans +=  pq2.top();
        pq2.pop();
    }

    cout<<ans<<endl;

    return 0;
}

