//Problem ID: CodeForces - 1132C (Painting the Fence)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 30/05/19
#include <bits/stdc++.h>
#define MAX 5005
using namespace std;

int counter[MAX], cs[MAX];
vector<pair<int, int> > vp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int l, r, n, q;

    cin>>n>>q;

    for(int i = 0; i < q; i++){
        cin>>l>>r;
        vp.push_back(make_pair(l, r));
        for(int j = l; j <= r; j++)
            counter[j]++;
    }

    int Max = 0;
    for(int i = 0; i < vp.size(); i++){
        memset(cs, 0, sizeof(cs));
        for(int j = vp[i].first; j <= vp[i].second; j++){
            counter[j]--;
        }
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(counter[j] == 1){
                cs[j] = 1 + cs[j-1];
                cnt++;
            }
            else{
                cs[j] = cs[j-1];
                if(counter[j] > 0)
                    cnt++;
            }
        }
        for(int j = i + 1; j < vp.size(); j++){
            int temp = cs[vp[j].second] - cs[vp[j].first - 1];
            int t = cnt - temp;
            Max = max(Max, t);
        }
        for(int j = vp[i].first; j <= vp[i].second; j++){
            counter[j]++;
        }
    }

    cout<<Max<<endl;

    return 0;
}