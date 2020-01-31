//Date: 27/01/20
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

vector<ii> vp;
int coordx[2][4], coordy[2][4];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            cin>>coordx[i][j]>>coordy[i][j];
        }
    }

    int minix = min(min(coordx[0][0], coordx[0][1]), min(coordx[0][2], coordx[0][3]));
    int maxix = max(max(coordx[0][0], coordx[0][1]), max(coordx[0][2], coordx[0][3]));

    int minjy = min(min(coordy[0][0], coordy[0][1]), min(coordy[0][2], coordy[0][3]));
    int maxjy = max(max(coordy[0][0], coordy[0][1]), max(coordy[0][2], coordy[0][3]));


    //cout<<minix<<" "<<maxix<<" "<<minjy<<" "<<maxjy<<endl;

    for(int i = minix; i <= maxix; i++){
        for(int j = minjy; j <= maxjy; j++){
            vp.pb(mk(i, j));
        }
    }

    sort(vp.begin(), vp.end());

    int idx1 = -1, idx2 = -1;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(coordx[1][i] == coordx[1][j]){
                if(coordy[1][i] <= coordy[1][j]){
                    idx1 = i;
                    idx2 = j;
                }
                else{
                    idx1 = j;
                    idx2 = i;
                }
            }
            else{

            }
        }
    }

    int diff = coordy[1][idx2] - coordy[1][idx1];

    int x = 0, y = coordy[1][idx2];
    for(int i = coordx[1][idx1], k = coordx[1][idx1]; i <= coordx[1][idx1] + diff / 2; i++, k--){
        for(int j = coordy[1][idx1] + x; j <= y; j++){
            //cout<<"("<<i<<","<<j<<")"<<" ";
            if(binary_search(vp.begin(), vp.end(), mk(i, j))){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        for(int j = coordy[1][idx1] + x; j <= y; j++){
            //cout<<"("<<k<<","<<j<<")"<<" ";
            if(binary_search(vp.begin(), vp.end(), mk(k, j))){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        x++, y--;
    }

    cout<<"NO"<<endl;

    return 0;
}