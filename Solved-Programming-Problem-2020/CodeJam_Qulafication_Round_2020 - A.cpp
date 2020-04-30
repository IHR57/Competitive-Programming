//Date: 04/04/2020
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
#define MAX 105
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}
 
int vis[MAX][MAX][2], arr[MAX][MAX];
bool mark[MAX][2];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	#ifndef ONLINE_JUDGE
 		freopen("input.txt", "r", stdin);
 		freopen("output.txt", "w", stdout);
 	#endif

 	int test, n, caseno = 1;

 	cin>>test;

 	while(test--){
 		cin>>n;
 		int rCnt = 0, cCnt = 0, dSum = 0;

 		memset(vis, 0, sizeof(vis));
 		memset(mark, 0, sizeof(mark));

 		for(int i = 0; i < n; i++){
 			for(int j = 0; j < n; j++){
 				cin>>arr[i][j];
 				if(!vis[i][arr[i][j]][0]){
 					vis[i][arr[i][j]][0] = 1;
 				}
 				else{
 					if(!mark[i][0])
 						rCnt++;
 					mark[i][0] = 1;
 				}
 				if(!vis[j][arr[i][j]][1]){
 					vis[j][arr[i][j]][1] = 1;
 				}
 				else{
 					if(!mark[j][1])
 						cCnt++;
 					mark[j][1] = 1;
 				}
 				if(i == j)
 					dSum += arr[i][j];
 			}
 		}

 		cout<<"Case #"<<caseno++<<": "<<dSum<<" "<<rCnt<<" "<<cCnt<<endl;
 	}
 
    return 0;
}