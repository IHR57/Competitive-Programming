//Problem ID: CodeForces - 864D (Make a Permutation!)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 03/03/19
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int counter[MAX], arr[MAX], cnt[MAX];
bool placed[MAX];
priority_queue<int,vector<int>,greater<int> > pq;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ans = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        counter[arr[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(!counter[i]){
            pq.push(i);
            ans++;
        }
    }

    for(int i = 0; i < n; i++){
        cnt[arr[i]]++;
        if(counter[arr[i]] > 1){
            if(!pq.empty()){
                int u = pq.top();
                if(u < arr[i] || placed[arr[i]]){
                    counter[arr[i]]--;
                    arr[i] = u;
                    pq.pop();
                }
            }
        }
        placed[arr[i]] = true;
    }

    cout<<ans<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
