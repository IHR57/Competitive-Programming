//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 998244353
#define MAX 400005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    string str;

    cin>>n;
    cin>>str;

    char ch1 = 'a', ch2 = 'a';
    vector<int>  ans;
    for(int i = 0; i < n; i++) {
        if(str[i] >= ch1) {
            ch1 = str[i];
            ans.pb(0);
        }
        else if(str[i] >= ch2) {
            ch2 = str[i];
            ans.pb(1);
        }
        else {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i];
    }
    cout<<endl;


    return 0;
}