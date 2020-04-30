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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	#ifndef ONLINE_JUDGE
 		freopen("input.txt", "r", stdin);
 		freopen("output.txt", "w", stdout);
 	#endif

 	int test, caseno = 1;
 	string str;

 	cin>>test;

 	while(test--){
 		cin>>str;
 		string ans = "";
 		for(int i = 0; i < (str[0] - 48); i++)
 			ans += "(";
 		ans += str[0];
 		int n = str.size();
 		for(int i = 1; i < n; i++){
 			int d = (str[i]-48) - (str[i-1] - 48);
 			if(d > 0){
 				for(int j = 0; j < d; j++)
 					ans += "(";
 			}
 			else if(d < 0){
 				for(int j = 0; j < abs(d); j++){
 					ans += ")";
 				}
 			}
 			ans += str[i];
 		}

 		for(int i = 0; i < (str[n-1] - 48); i++)
 			ans += ")";

 		cout<<"Case #"<<caseno++<<": "<<ans<<endl;

 	}
 	
 
    return 0;
}