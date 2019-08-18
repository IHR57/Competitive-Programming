#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v[26];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, t;

    cin>>s>>t;
    set<int> st;
    for(int i = 0; i < s.size(); i++){
        v[s[i]-'a'].pb(i);
        st.insert(s[i]-'a');
    }
    for(int i = 0; i < t.size(); i++){
        if(!st.count(t[i]-'a')){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll ans = 0;
    int prev = -1;
    for(int i = 0; i < t.size(); i++){
        if(i == t.size())
            break;
        int idx = lower_bound(v[t[i]-'a'].begin(), v[t[i]-'a'].end(), prev) - v[t[i]-'a'].begin();
//        cout<<prev<<" "<<idx<<endl;
        if(idx == v[t[i]-'a'].size()){
            ans += (ll) s.size();
            prev = v[t[i]-'a'][0];
        }
        else if(v[t[i]-'a'][idx] == prev){
            if(idx + 1 >= v[t[i]-'a'].size()){
                ans += (ll) s.size();
                prev = v[t[i]-'a'][0];
            }
            else{
                prev = v[t[i]-'a'][idx+1];
            }
        }
        else if(v[t[i]-'a'][idx] < prev){
            ans += (ll) s.size();
            prev = v[t[i]-'a'][0];
        }
        else if(v[t[i]-'a'][idx] > prev){
            prev = v[t[i]-'a'][idx];
        }
    }

    cout<<ans + prev + 1<<endl;

    return 0;
}

