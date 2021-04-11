//Date: 05/02/2020
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> v[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test;
    string s, t;

    cin>>test;

    while(test--){
        cin>>s>>t;
        int n = s.size();
        for(int i = 0; i < n; i++){
            v[s[i]-'a'].pb(i);
        }

        int cnt = 0;
        n = t.size();

        int idx = -1;
        bool flag = true;

        for(int i = 0; i < n; i++){
            int x = t[i] - 'a';
            if(v[x].empty()){
                flag = false;
                break;
            }
            int tx = lower_bound(v[x].begin(), v[x].end(), idx) - v[x].begin();
            if(tx >= v[x].size()){
                cnt++;
                tx = lower_bound(v[x].begin(), v[x].end(), -1) - v[x].begin();
                idx = v[x][tx] + 1;
            }
            else{
                idx = v[x][tx] + 1;
            }

        }

        (flag) ? cout<<cnt + 1<<endl : cout<<-1<<endl;
        for(int i = 0;  i < 30; i++)
            v[i].clear();
    }

    return 0;
}