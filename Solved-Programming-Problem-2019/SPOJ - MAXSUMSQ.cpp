//Problem ID: SPOJ - MAXSUMSQ (Maximum Sum Sequences)
//Programmer: IQBAL HOSSAIN     Category: DP
//Date: 29/09/19
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
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int test, caseno = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int Max = -2000000000;
        int s = 0, cntZero = 0;
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            s += arr[i];
            if(s > Max){
                Max = s;
                cnt = (ll) (cntZero + 1);
            }
            else if(s == Max){
                cnt++;
                cnt += (ll) (cntZero);
            }
            if(s == 0){
                cntZero++;
            }
            else if(s < 0){
                s = 0;
                cntZero = 0;
            }
        }


        printf("%d %lld\n", Max, cnt);
    }

    return 0;
}