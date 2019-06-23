//Problem ID: AtCoder - abc127_d
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 29/05/19
//Problem Link: https://atcoder.jp/contests/abc127/tasks/abc127_d
#include <bits/stdc++.h>
#define MAX 100005
#define read (freopen("input.txt", "r", stdin));
#define write (freopen("output.txt", "w", stdout));
using namespace std;

typedef long long ll;

int counter[MAX];
map<int, int> mp;
set<int> s;
int n, m, arr[MAX];

int main()
{
    //read; write;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int b, c;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int idx = 1;
    for(int i = 0; i < m; i++){
        cin>>b>>c;
        if(mp[c] == 0){
            mp[c] = idx++;
        }
        counter[mp[c]] += b;
        s.insert(c);
    }

    int u;
    for(int i = 0; i < n; i++){
        if(!s.empty())
            u = *s.rbegin();
        if(!s.empty() && arr[i] < u){
            arr[i] = u;
            counter[mp[u]]--;
            if(counter[mp[u]] <= 0){
                s.erase(u);
            }
        }
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (ll) arr[i];
    }
    cout<<sum<<endl;


    return 0;
}