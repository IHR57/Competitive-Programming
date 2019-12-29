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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

char str[100];
int n;

bool isValid(int x)
{
    if(str[x] == 'B' || str[x] == 'D' || str[x] == 'S')
        return false;
    if(x - 1 >= 0 && str[x-1] == 'S')
        return false;
    if((x + 1 < n && str[x+1] == 'S') || (x + 1 < n && str[x+1] == 'B') || (x + 2 < n && str[x+2] == 'B')){
        return false;
    }

    return true;
}

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
        scanf("%s", str);
        n = strlen(str);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(isValid(i)){
                cnt++;
            }
        }

        printf("Case %d: %d\n", caseno++, cnt);
    }

    return 0;
}
