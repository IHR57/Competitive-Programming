//Date: 01/11/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

set<int> s[30];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string str;
    int q, u, v, type;
    char ch;

    cin>>str;

    for(int i = 0; i < (int) str.size(); i++){
        s[str[i]-'a'].insert(i);
    }

    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>type;
        if(type == 1){
            cin>>u>>ch;
            u--;
            s[str[u]-'a'].erase(u);
            str[u] = ch;
            s[str[u]-'a'].insert(u);
        }
        else{
            cin>>u>>v;
            u--, v--;
            int cnt = 0;
            set<int> :: iterator it;
            for(int j = 0; j < 26; j++){
                it = s[j].lower_bound(u);
                if(it != s[j].end()){
                    if(*it <= v)
                        cnt++;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}