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
#define MAX 4005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cs[MAX][3];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    string str;

    cin>>n;
    cin>>str;

    for(int i = 0; i < n; i++){
        cs[i+1][0] = cs[i][0];
        cs[i+1][1] = cs[i][1];
        cs[i+1][2] = cs[i][2];

        if(str[i] == 'R')
            cs[i+1][0] = cs[i][0] + 1;
        else if(str[i] == 'G')
            cs[i+1][1] = cs[i][1] + 1;
        else
            cs[i+1][2] = cs[i][2] + 1;

    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int d = j - i;
            if(str[i] != str[j]){
                if(str[i] == 'R' && str[j] == 'G'){
                    int temp = cs[n][2] - cs[j][2];
                    if(str[j+d] == 'B')
                        temp--;
                    ans += (ll) temp;
                }
                else if(str[i] == 'R' && str[j] == 'B'){
                    int temp = cs[n][1] - cs[j][1];
                    if(str[j+d] == 'G')
                        temp--;
                    ans += (ll) temp;
                }
                else if(str[i] == 'G' && str[j] == 'R'){
                    int temp = cs[n][2] - cs[j][2];
                    if(str[j+d] == 'B')
                        temp--;
                    ans += (ll) temp;
                }
                else if(str[i] == 'G' && str[j] == 'B'){
                    int temp = cs[n][0] - cs[j][0];
                    if(str[j+d] == 'R')
                        temp--;
                    ans += (ll) temp;
                }
                else if(str[i] == 'B' && str[j] == 'R'){
                    int temp = cs[n][1] - cs[j][1];
                    if(str[j+d] == 'G')
                        temp--;
                    ans += (ll) temp;
                }
                else if(str[i] == 'B' && str[j] == 'G'){
                    int temp = cs[n][0] - cs[j][0];
                    if(str[j+d] == 'R')
                        temp--;
                    ans += (ll) temp;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
