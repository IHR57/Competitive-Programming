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

    int test;

    cin>>test;

    while(test--){
        set<int> s;
        int n, val;
        cin>>n;

        map<int, int> mp;
        int idx = 1;

        vector<int> cnt(n + 2, 0);

        for(int i = 0; i < n; i++){
            cin>>val;
            if(mp[val] == 0)
                mp[val] = idx++;
            cnt[mp[val]]++;
            s.insert(val);
        }

        vector<int> res;

        int t = 0;
        while(true){
            res.pb(*s.rbegin());
            t++;
            cnt[mp[*s.rbegin()]]--;
            if(cnt[mp[*s.rbegin()]] <= 0)
                s.erase(*s.rbegin());
            if(t >= n)
                break;

            res.pb(*s.begin());
            cnt[mp[*s.begin()]]--;

            if(cnt[mp[*s.begin()]] <= 0)
                s.erase(*s.begin());
            t++;
            if(t >= n)
                break;
        }
        reverse(res.begin(), res.end());

        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
