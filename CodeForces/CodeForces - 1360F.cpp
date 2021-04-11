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

string str[15];
int n, m;

bool allValid(string st)
{
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(str[i][j] != st[j])
                cnt++;
        }
        if(cnt > 1)
            return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test;

    cin>>test;

    while(test--) {
        cin>>n>>m;
        for(int i = 0; i < n; i++) {
            cin>>str[i];
        }

        string temp = str[0];

        bool found = false;
        string res;
        for(int i = 0; i < m; i++) {
            str[0] = temp;
            for(int j = 0; j < 26; j++) {
                str[0][i] = (char) j + 97;
                //cout<<str[0]<<endl;
                if(allValid(str[0])) {
                    res = str[0];
                    found = true;
                    break;
                }
            }
        }
        if(!found) {
            cout<<-1<<endl;
            continue;
        }
        cout<<res<<endl;
    }
    return 0;
}
