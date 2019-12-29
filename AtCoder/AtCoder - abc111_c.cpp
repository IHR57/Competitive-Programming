//Problem ID: AtCoder - abc111_c (/\/\/\/)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 12/07/19
//Problem Link: https://atcoder.jp/contests/abc111/tasks/arc103_a
#include <bits/stdc++.h>
#define MAX 100005
#define mp make_pair
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int cnt1[MAX], cnt2[MAX], arr[MAX], vis1[MAX], vis2[MAX];
priority_queue<ii> pq1, pq2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        (i % 2) ? cnt2[arr[i]]++ : cnt1[arr[i]]++;
    }

    for(int i = 0; i < n ; i++){
        if(i % 2 && !vis2[arr[i]]){
            vis2[arr[i]] = 1;
            pq2.push(mp(cnt2[arr[i]], arr[i]));
        }
        else if(i % 2 == 0 && !vis1[arr[i]]){
            vis1[arr[i]] = 1;
            pq1.push(mp(cnt1[arr[i]], arr[i]));
        }
    }

    ii u = pq1.top(), v = pq2.top();
    int ans;
    if(u.second != v.second){
        ans = (n / 2) - u.first + (n / 2) - v.first;
        cout<<ans<<endl;
        return 0;
    }

    int p = 0, q = 0, r = 0, s = 0;
    p = u.first;
    pq1.pop();
    q = v.first;
    pq2.pop();
    if(!pq1.empty())
        r = pq1.top().first;
    if(!pq2.empty())
        s = pq2.top().first;

    ans = (n / 2) - p + (n / 2) - s;
    ans = min(ans, (n / 2) - q + (n / 2) - r);

    cout<<ans<<endl;
    
    return 0;
}