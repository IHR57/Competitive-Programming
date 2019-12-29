#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
vector<ii> vp;

bool compare(ii A, ii B)
{
    return A.second < B.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    cin>>n;

    bool flag = true;
    for(int i = 0; i < n; i++){
        cin>>a>>b;
        if(a > b)
            flag = false;
        vp.push_back(make_pair(a, b));
    }

    if(!flag){
        cout<<"No"<<endl;
        return 0;
    }
    sort(vp.begin(), vp.end(), compare);

    ll t = 0;
    for(int i  = 0; i < vp.size(); i++){
        //cout<<vp[i].first<<" "<<vp[i].second<<endl;
        t += (ll) vp[i].first;
        if(t > vp[i].second){
            flag = false;
        }
    }

    if(!flag){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

    return  0;
}

