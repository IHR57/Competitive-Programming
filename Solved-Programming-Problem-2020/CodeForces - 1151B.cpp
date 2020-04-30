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

int arr[505][505];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, m;

    cin>>n>>m;

    set<int> s[n+1];
    int k = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
            s[i].insert(arr[i][j]);
            if(s[i].size() > 1){
                k = i;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans ^= *s[i].begin();
    }

    if(ans == 0 && k == -1){
        cout<<"NIE"<<endl;
        return 0;
    }

    vector<int> res;
    if(ans == 0 && k != -1){
        s[k].erase(*s[k].begin());
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == *s[i].begin()){
                res.pb(j + 1);
                break;
            }
        }
    }

    cout<<"TAK"<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;


    return 0;
}