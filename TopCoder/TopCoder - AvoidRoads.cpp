//Problem ID: TopCoder - AvoidRoads
//Programmer: IQBAL HOSSAIN     Description: DP
//Date: 09/09/19
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

typedef unsigned long long ll;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

ll dp[MAX][MAX];
int cell[MAX][MAX];

int fx[] = {1, 0};
int fy[] = {0, 1};

class AvoidRoads
{
    public:
        ll numWays(int width, int height, vector<string> bad)
        {   
            set<pair<ii, ii> > s;
            for(int i = 0; i < bad.size(); i++){
                int a = 0, b = 0, c = 0, d = 0;
                int j = 0;
                while(bad[i][j] != ' '){
                    a = a * 10 + (bad[i][j] - 48);
                    j++;
                }
                j++;
                while(bad[i][j] != ' '){
                    b = b * 10 + (bad[i][j] - 48);
                    j++;
                }
                j++;
                while(bad[i][j] != ' '){
                    c = c * 10 + (bad[i][j] - 48);
                    j++;
                }
                j++;
                while(j < bad[i].size()){
                    d = d * 10 + (bad[i][j] - 48);
                    j++;
                }
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                s.insert(mk(mk(a, b), mk(c, d)));
                s.insert(mk(mk(c, d), mk(a, b)));
            }

            dp[0][0] = 1;
            for(int i = 0; i <= width; i++){
                for(int j = 0; j <= height; j++){
                    for(int k = 0; k < 2; k++){
                        int tx = i + fx[k];
                        int ty = j + fy[k];
                        if(!s.count(mk(mk(i, j), mk(tx, ty)))){
                            dp[tx][ty] += dp[i][j];
                        }
                    }
                }
            }

            return dp[width][height];
        }

};
// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     AvoidRoads obj = AvoidRoads();
//     vector<string> str;
//     //str.pb("20 0 21 0"), str.pb("30 31 31 31");
//     cout<<obj.numWays(35, 31, str)<<endl;

//     return 0;
// }
