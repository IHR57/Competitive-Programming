//Problem ID: CodeForces - 1102B (Array K-Colouring)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 09/02/19
#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

int counter[MAX], arr[MAX], temp[MAX];
int visited[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        counter[arr[i]]++;
    }

    queue<int> q;
    for(int i = 1; i <= k; i++){
        q.push(i);
    }

    for(int i = 0; i < MAX; i++){
        if(counter[i] > k){
            cout<<"NO"<<endl;
            return 0;
        }
        if(counter[i]){
            for(int j = 0; j < n ; j++){
                if(arr[j] == i){
                    int u = q.front();
                    q.pop();
                    visited[u] = 1;
                    temp[j] = u;
                    q.push(u);
                }
            }
        }
    }
    for(int i = 1; i <= k; i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < n; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    return 0;
}
