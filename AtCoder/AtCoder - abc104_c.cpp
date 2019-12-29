#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 505
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int p[MAX], c[MAX], score[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, g;
    cin>>n>>g;
    for(int i = 0; i < n; i++){
        cin>>p[i]>>c[i];
    }
    for(int i = 0; i < n; i++)
        score[i] = 100 * (i + 1);

    int Min = 1e8;
    for(int i = 0; i < (1 << n); i++){
        bitset<10> bit(i);
        int cnt = 0;
        int temp = g;
        for(int j = 0; j < n; j++){
            if(bit[j]){
                temp -= (p[j] * score[j]) + c[j];
                cnt += p[j];
            }
        }
        for(int j = n - 1; j >= 0; j--){
            if(!bit[j]){
                int t = min(p[j], (max(0, temp) + score[j] - 1) / score[j]);
                cnt += t;
                temp -= (t * score[j]);
            }
        }
        Min = min(Min, cnt);
    }

    cout<<Min<<endl;

    return 0;
}
