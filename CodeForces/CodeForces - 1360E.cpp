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

char cell[55][55];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;

    cin>>test;

    while(test--) {
        cin>>n;
        int dir[n+1][n+1] = {0};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin>>cell[i][j];
            }
        }

        bool found = true;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(cell[i][j] == '1'){
                    if(i + 1 < n && cell[i+1][j] == '0' && j + 1 < n && cell[i][j+1] == '0'){
                        found = false;
                        break;
                    }
                }
            }
        }

        (found) ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    }

    return 0;
}
