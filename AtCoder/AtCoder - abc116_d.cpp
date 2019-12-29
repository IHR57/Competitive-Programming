//Problem ID: AtCoder - abc116_d (Various Sushi)
//Programmer: IQBAL HOSSAIN     Description: Data Structures/Sorting
//Date: 13/06/19
//Problem Link: https://atcoder.jp/contests/abc116/tasks/abc116_d
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int  counter[MAX];

vector<pii> vp;

bool compare(pii A, pii B)
{
    return A.second > B.second;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt","w", stdout);
    // #endif
    int n, k, u, v;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>u>>v;
        vp.push_back(make_pair(u, v));
    }

    sort(vp.begin(), vp.end(), compare);
    priority_queue<int, vector<int>, greater<int> > pq;

    ll sum = 0, cnt = 0;
    for(int i = 0; i < k; i++){
        sum += vp[i].second;
        counter[vp[i].first]++;
        if(counter[vp[i].first] >= 2)
            pq.push(vp[i].second);
        else
            cnt++;
    }

    ll ans = sum + (cnt * cnt);

    for(int i = k; i < n; i++){
        if(pq.empty())
            break;
        if(counter[vp[i].first] >= 1)
            continue;
        counter[vp[i].first]++;
        int temp = pq.top();
        pq.pop();

        sum -= temp;
        sum += vp[i].second;
        cnt++;
        ans = max(ans, sum + (cnt * cnt));
    }

    cout<<ans<<endl;

    return 0;
}