//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    map<string, int> mp;

    cin>>n>>m;

    vector<string> v1, v2, v;
    multiset<int> s;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        mp[str]++;
        v.pb(str);
    }

    string ms = "";
    for(int i = 0; i < n; i++){
        string temp = v[i];
        reverse(temp.begin(), temp.end());
        if(temp == v[i]){
            if(mp[temp] >= 2){
                v1.pb(v[i]);
                v2.pb(v[i]);
                mp[v[i]] -= 2;
            }
            else{
                ms = temp;
                mp[v[i]]--;
            }
        }
        if(mp[temp]){
            v1.pb(v[i]);
            v2.pb(temp);
            mp[v[i]]--;
            mp[temp]--;
        }
    }
    string res = "";
    for(int i = 0; i < v1.size(); i++){
        res += v1[i];
    }
    res += ms;
    for(int i = v2.size() - 1; i >= 0; i--){
        res += v2[i];
    }

    cout<<res.size()<<endl;
    cout<<res<<endl;

    return 0;
}
