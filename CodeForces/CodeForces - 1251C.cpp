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

ll arr[35];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test;
    string str;

    cin>>test;

    while(test--){
        cin>>str;
        string stro = "", stre = "";
        for(int i = 0; i < str.size(); i++){
            if((str[i]-48) & 1)
                stro += str[i];
            else
                stre += str[i];
        }

        int x = 0, y = 0, n = stro.size(), m = stre.size();

        string ans = "";

        while(!(x >= n && y >= m)) {
            if(x >= n){
                ans += stre[y];
                y++;
                continue;
            }
            if(y >= m){
                ans += stro[x];
                x++;
                continue;
            }
            if(stre[y] < stro[x]) {
                ans += stre[y];
                y++;
            }
            else{
                ans += stro[x];
                x++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}