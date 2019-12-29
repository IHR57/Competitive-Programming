//Problem ID: CodeForces - 962D (Merge Equals)
//Programmer: IQBAL HOSSAIN     Description: Data Structure/Implementation
//Date: 28/04/19
#include <bits/stdc++.h>
#define MAX 150005
using namespace std;

typedef long long ll;

ll arr[MAX];
set<ll> ss[MAX*2];
set<ll> s;
map<ll, ll> mp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;

    int idx = 1;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        if(mp[arr[i]] == 0){
            mp[arr[i]] = idx++;
            s.insert(arr[i]);
        }
        ss[mp[arr[i]]].insert(i);
    }

    int cnt = 0;
    while(!s.empty()){
        ll temp = mp[*s.begin()];
        if(ss[temp].size() >= 2){
            int j = 0;
            for(set<ll> :: iterator it = ss[temp].begin(); it != ss[temp].end(); it++){
                if(j == ss[temp].size() - 1 && ss[temp].size() % 2)
                    continue;
                if(j % 2){
                    ll k = (*s.begin()) * 2;
                    if(mp[k] == 0){
                        mp[k] = idx++;
                        s.insert(k);
                    }
                    ss[mp[k]].insert(*it);
                    arr[*it] = (*s.begin() * 2);
                }
                else{
                    arr[*it] = -1;
                    cnt++;
                }
                j++;
            }
        }
        s.erase(*s.begin());
    }

    cout<<(n - cnt)<<endl;
    for(int i = 1; i <= n; i++){
        if(arr[i] != -1){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;

    return 0;
}
