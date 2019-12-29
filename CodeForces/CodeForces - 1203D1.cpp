//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define debug (printf("PINK FLOYD:)\n"))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define EPS 1e-8
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

int dp[205][205];

int solve(int i, int j, string s, string t)
{
    int k = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == t[k]){
            k++;
        }
    }

    return k;
}

vector<string> vs;
map<ii, int> MP;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, t;

    cin>>s>>t;

    int len = s.size();
    int n = t.size();

    int low = 0, high = len, mid, ans;
    int idx = 0;
    for(int i = 0; i < len; i++){
        string z = "";
        int k = i;
        MP[mp(i, 0)] = vs.size();
        vs.pb("");
        for(int j = 1; j <= len - i; j++){
            MP[mp(i, j)] = vs.size();
            z += s[k];
            vs.pb(z);
            k++;
            //cout<<z<<endl;
        }
    }
    while(low <= high){
        mid = (low + high + 1) >> 1;
        bool flag = false;
        //cout<<mid<<endl;
        for(int i = 0; i <= len - mid; i++){
            string temp = "";
            temp += vs[MP[mp(0, i)]];
            temp += vs[MP[mp(i + mid, len - i - mid)]];
            //cout<<vs[MP[mp(0, i)]]<<" "<<vs[MP[mp(i + mid, len - i - mid)]]<<endl;
            //cout<<temp<<endl;
            mem(dp, -1);
            int res = solve(0, 0, temp, t);
            if(res >= n){
                flag = true;
                break;
            }
        }
        if(flag){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
