#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define dis(x1, y1, x2, y2) ((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2))
using namespace std;

class ATaleOfThreeCities
{
    public:
         double solve(vector<int> ax, vector<int> ay, vector<int> bx, vector<int> by, vector<int> cx, vector<int> cy)
         {
             double dist = (double) 1e8, dist1 = (double) 1e8, dist2 = (double) 1e8, temp;
             for(int i = 0; i < ax.size(); i++){
                for(int j = 0; j < bx.size(); j++){
                    temp = (double) sqrt(dis(ax[i], ay[i], bx[j], by[j]));
                    dist1 = min(dist1, temp);
                }
                for(int j = 0; j < cx.size(); j++){
                    temp = (double) sqrt(dis(ax[i], ay[i], cx[j], cy[j]));
                    dist2 = min(dist2, temp);
                }
                dist = min(dist, dist1 + dist2);
             }
             return dist;
         }
         double connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy)
         {
             double res = (double) 1e8;
             res = min(res, solve(ax, ay, bx, by, cx, cy));
             res = min(res, solve(bx, by, ax, ay, cx, cy));
             res = min(res, solve(cx, cy, ax, ay, bx, by));

             return res;
         }
};
//
//int main()
//{
//
//}
