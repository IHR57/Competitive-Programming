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

int vis[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, n, a, b,  c;
    string str;

    cin>>test;

    while(test--){
        cin>>n;
        cin>>a>>b>>c;
        cin>>str;

        int len = str.length();

        int need = (len & 1) ? (len / 2) + 1 : len / 2;
        int cnt = 0;

        mem(vis, 0);
        for(int i = 0; i < len; i++){
            if(str[i] == 'R'){
                if(b > 0){
                    cnt++;
                    vis[i] = 2;
                    b--;
                }
            }
            else if(str[i] == 'P'){
                if(c > 0){
                    cnt++;
                    vis[i] = 3;
                    c--;
                }
            }
            else if(str[i] == 'S'){
                if(a > 0){
                    cnt++;
                    vis[i] = 1;
                    a--;
                }
            }
        }

        if(cnt >= need){
            cout<<"YES"<<endl;
            for(int i = 0; i < len; i++){
                if(!vis[i]){
                    if(a){
                        vis[i] = 1;
                        a--;
                    }
                    else if(b){
                        vis[i] = 2;
                        b--;
                    }
                    else if(c){
                        vis[i] = 3;
                        c--;
                    }
                }
            }

            for(int i = 0; i < len; i++){
                if(vis[i] == 1)
                    cout<<"R";
                else if(vis[i] == 2)
                    cout<<"P";
                else if(vis[i] == 3)
                    cout<<"S";
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
