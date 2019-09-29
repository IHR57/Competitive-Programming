//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int ans[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, test;
    string str;

    cin>>test;

    while(test--){
        cin>>n;
        cin>>str;
        memset(ans, 0, sizeof(ans));
        bool hasAns = false;
        for(int i = 0; i < 10; i++){
            bool flag = true;
                
            int x = i, t = 0;
            for(int j = 0; j < n; j++){
                if((str[j] - 48) < i){
                    ans[j] = 1;
                }
                else if((str[j] - 48) == i){
                    if(x == i){
                        ans[j] = 2;
                    }
                    else
                        ans[j] = 1;
                }
                else
                    ans[j] = 2;
                if(ans[j] == 1){
                    if((str[j] - 48) >= t){
                        t = (str[j] - 48);
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
                else{
                    if((str[j] - 48) >= x){
                        x = (str[j] - 48);
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                for(int j = 0; j < n; j++)
                    cout<<ans[j];
                cout<<endl;
                hasAns = true;
                break;
            }
        }
        if(!hasAns){
            cout<<"-"<<endl;
            continue;
        }
    }
    return 0;
}
