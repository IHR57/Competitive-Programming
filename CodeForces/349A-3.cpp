#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <stack>
#define MAX 100005
#define pb push_back
#define all(c) (c.begin(), c.end())
#define mem(a, b) memset(a, b, sizeof(a))
#define EPS 1e-10
#define PI 3.14159265358979323846
#define MOD 10000000007
#define mp make_pair
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;
typedef vector< vector<int> >vii;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;

const int inf = 1<<29;

int main()
{
	//read; write;
	int n, value, flag = 0;
	int ruble25 = 0, ruble50 = 0, ruble100 = 0;

    cin>>n;
	for(int i =  0; i < n; i++){
        cin>>value;
        if(i == 0 ){
            if(value == 25){
                ruble25++;
            }
            else{
                flag = 1;
            }
        }
        else{
            int temp = value - 25;
            if(temp == 25){
                if(ruble25){
                    ruble25--;
                }
                else
                    flag = 1;
            }
            else if(temp == 75){
                if(ruble25 > 0 && ruble50 > 0){
                    ruble25--;
                    ruble50--;
                }
                else if(ruble25 >=3 && ruble50 < 1){
                    ruble25 -= 3;
                }
                else{
                    flag = 1;
                }
            }
            if(value == 25) ruble25++;
            else if(value == 50) ruble50++;
            else    ruble100++;
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }

	return 0;
}
