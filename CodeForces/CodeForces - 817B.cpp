#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val;
    vector<int> v, temp;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>val;
        v.push_back(val);
    }

    temp = v;
    sort(temp.begin(), temp.end());

    int fst = temp[0], snd = temp[1], thrd = temp[2];
    int cnt = 0, flag = 0;
    ll ans = 0;
    if(fst == snd && snd != thrd){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == thrd){
                ans++;
            }

        }
        cout<<ans<<endl;
    }
    else if(fst != snd && snd == thrd){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == snd){
                ans++;
            }
        }
        ans = (ans * 1LL * (ans - 1)) / 2;
        cout<<ans<<endl;
    }
    else if(fst != snd && snd != thrd){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == thrd){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    else{
        for(int i = 0; i < v.size(); i++){
            if(v[i] == fst){
                ans++;
            }
        }
        ans -= 2;
        ans = (ans * 1LL * (ans + 1) * (ans + 2)) / 6;
        cout<<ans<<endl;
    }

    return 0;
}
