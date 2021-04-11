//Date: 31/01/20
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 1005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int mat[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, a, b;

    cin>>n>>a>>b;

    if(a > 1 && b > 1){
        cout<<"NO"<<endl;
        return 0;
    }

    if(n == 1 && a == 1 && b == 1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }

    if(a == 1 && b == 1){
        if(n <= 3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    int cmp = n - max(a, b) + 1;

    for(int i = 1; i < cmp; i++){
        mat[i][i+1] = 1;
        mat[i+1][i] = 1;
    }

    if(a == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mat[i][j] == 1)
                    mat[i][j] = 0;
                else
                    mat[i][j] = 1;
            }
            mat[i][i] = 0;
        }
    }

    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }

    return 0;
}