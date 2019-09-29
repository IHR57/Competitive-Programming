//Problem ID: TopCoder - ChessMetric
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

ll dp[MAX][MAX][55];

int fx[] = { -2, -2, -1, -1,  1,  1,  2,  2, -1, -1, -1,  0,  0,  1, 1, 1 };
int fy[] = { -1,  1, -2,  2, -2,  2, -1,  1, -1,  0,  1, -1,  1, -1, 0, 1 };

class ChessMetric
{
    public:
         long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
         {
            int sx = start[0], sy = start[1];
            int tx = end[0], ty = end[1];
            dp[sx][sy][0] = 1;
            for(int i = 1; i <= numMoves; i++){
                for(int x = 0; x < size; x++){
                    for(int y = 0; y < size; y++){
                        for(int k = 0; k < 16; k++){
                            int a = x + fx[k];
                            int b = y + fy[k];
                            if(a < 0 || b < 0 || a >= size || b >= size)
                                continue;
                            dp[a][b][i] += dp[x][y][i-1];
                        }
                    }
                }
            }

            return dp[tx][ty][numMoves];
         }
};
// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int size, moves;
//     vector<int> start(2), end(2);
//     cin>>size>>moves;
//     cin>>start[0]>>start[1];
//     cin>>end[0]>>end[1];
//     ChessMetric obj = ChessMetric();
//     cout<<obj.howMany(size, start, end, moves)<<endl;

//     return 0;
// }
