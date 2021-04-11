//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000009
#define MAX 300005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int rowXor[105], colXor[105];
int matrix[105][105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i = 1; i <= n; i++)
        cin>>rowXor[i];
    for(int i = 1; i <= m; i++)
        cin>>colXor[i];

    int cXor = 0;
    bool found = true;
    for(int i = 1; i <= n; i++) {
        int rXor = 0;
        for(int j = 1; j < m; j++) {
            if(i == 1) {
                matrix[i][j] = colXor[j];
                rXor ^= colXor[j];
            }
        }
        if(i != n) {
            matrix[i][m] = rowXor[i] ^ rXor;
            cXor ^= matrix[i][m];
        }
        else {
            if((cXor ^ rowXor[n]) != colXor[m]) {
                found = false;
                break;
            }
            else{
                matrix[i][m] = rowXor[n];
            }
        }
    }

    if(!found) {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
