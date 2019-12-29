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

char str[105];

bool isArrow(int x, int y)
{
    if(str[x] == '<'){
        char arrowType = '$';
        if(x + 1 <= y && (str[x+1] == '-' || str[x+1] == '='))
            arrowType = str[x+1];
        for(int i = x + 1; i <= y; i++){
            if(str[i] != arrowType)
                return false;
        }
    }
    else if(str[y] == '>'){
        char arrowType = '$';
        if(y - 1 >= x && (str[y-1] == '-' || str[y-1] == '='))
            arrowType = str[y-1];
        for(int i = y - 1; i >= x; i--){
            if(str[i] != arrowType)
                return false;
        }
    }
    else
        return false;

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
        int n = strlen(str);

        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isArrow(i, j)){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}
