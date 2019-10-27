//Date: 19/10/19
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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

class BallsOnAMeadow
{
    public:
        int count(string str)
        {
            int n = str.length(), cnt = 0;
            for(int i = 0; i < n - 1; i++){
                if(str[i] == '|' && str[i+1] == ')'){
                    cnt++;
                    i++;
                }
                if(str[i] == '(' && (str[i+1] == ')' || str[i+1] == '|')){
                    cnt++;
                    i++;
                }
            }

            return cnt;
        }

};

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif

//     return 0;
// }