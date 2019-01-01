#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll s, k;

    cin>>s>>k;

    vector<ll> v;

    if(s == 1){
        cout<<2<<endl;
        cout<<1<<" "<<0<<endl;
        return 0;
    }
    v.push_back(1);

    int j = 1;

    while(1){
        ll sum = 0;
        int cnt = 0;
        for(int i = v.size() - 1; i >= 0; i--){
            cnt++;
            sum += v[i];
            if(cnt == k)
                break;
            //cout<<v[i]<<endl;
        }
        if(sum <= s)
            v.push_back(sum);
        else
            break;
    }

    v.erase(unique(v.begin(), v.end()), v.end());

    vector<ll> temp;

    while(s != 0){
        int idx = lower_bound(v.begin(), v.end(), s) - v.begin();
        if(binary_search(v.begin(), v.end(), s)){
            temp.push_back(v[idx]);
            s -= v[idx];
        }
        else{
            temp.push_back(v[idx-1]);
            s -= v[idx-1];
        }
    }

    if(temp.size() == 1){
        cout<<2<<endl;
        cout<<temp[0]<<" "<<0<<endl;
        return 0;
    }
    cout<<temp.size()<<endl;
    for(int i = 0; i < temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    return 0;
}
