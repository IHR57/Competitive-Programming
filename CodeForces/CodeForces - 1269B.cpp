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
#define MAX 2005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<int> a, b;
set<int> s[2*MAX], s1[2*MAX];

int res[MAX*2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        a.pb(val);
    }
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        b.pb(val);
    }

    int idx = 1;
    vector<int> candidate;

    for(int i = 0; i < n; i++){
        int t;
        if(b[i] >= a[0]){
            t = (b[i] - a[0]);
        }
        else{
            t = m - (a[0] - b[i]);
        }
        candidate.pb(t);
    }

    sort(b.begin(), b.end());

    int Min = 1e9;
    for(int i = 0; i < candidate.size(); i++){
        vector<int> temp;
        //cout<<candidate[i]<<endl;
        for(int j = 0; j < n; j++){
            temp.pb((a[j] + candidate[i]) % m);
        }
        sort(temp.begin(), temp.end());
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(b[j] != temp[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            Min = min(Min, candidate[i]);
        }
    }

    cout<<Min<<endl;

    return 0;
}
