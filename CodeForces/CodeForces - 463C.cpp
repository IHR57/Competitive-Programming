/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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
#define MAX 2005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll arr[MAX][MAX];
ll dig1[MAX][MAX], dig2[MAX][MAX];
ll oddMax = -1, evenMax = -1, ox, oy, ex, ey;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i - 1 >= 0 && j + 1 < n){
                dig1[i][j] = dig1[i-1][j+1] + arr[i][j];
            }
            else
                dig1[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            if(i - 1 >= 0 && j - 1 >= 0){
                dig2[i][j] = dig2[i-1][j-1] + arr[i][j];
            }
            else
                dig2[i][j] = arr[i][j];
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = 1; j < n; j++){
            dig1[i][j] = dig1[i+1][j-1];
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            dig2[i][j] = dig2[i+1][j+1];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i + j) & 1){
                if(dig1[i][j] + dig2[i][j] - arr[i][j] > oddMax){
                    oddMax = dig1[i][j] + dig2[i][j] - arr[i][j];
                    ox = i, oy = j;
                }
            }
            else{
                if(dig1[i][j] + dig2[i][j] - arr[i][j] > evenMax){
                    evenMax = dig1[i][j] + dig2[i][j] - arr[i][j];
                    ex = i, ey = j;
                }
            }
        }
    }

    ll Max = -1;
    int sx, sy, tx, ty;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i + j) & 1){
                if(dig1[i][j] + dig2[i][j] - arr[i][j] + evenMax > Max){
                    Max = dig1[i][j] + dig2[i][j] - arr[i][j] + evenMax;
                    sx = i, sy = j, tx = ex, ty = ey;
                }
            }
            else{
                if(dig1[i][j] + dig2[i][j] - arr[i][j] + oddMax > Max){
                    Max = dig1[i][j] + dig2[i][j] - arr[i][j] + oddMax;
                    sx = i, sy = j, tx = ox, ty = oy;
                }
            }
        }
    }

    cout<<Max<<endl;
    cout<<sx + 1<<" "<<sy + 1<<" "<<tx + 1<<" "<<ty + 1<<endl;
    

    return 0;
}
