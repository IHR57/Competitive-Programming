/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
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

bool isLeapYear(int year)
{
    if(year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int d, m, y, qy, cnt, test, caseno = 1;

    cin>>test;

    while(test--){
        cin>>d>>m>>y>>qy;

        cnt = 0;
        if(m != 2){
            cnt += (qy - y);
        }
        else{
            if(d != 29)
                cnt += (qy - y);
            else{
                for(int i = y + 1; i <= qy; i++){
                    if(isLeapYear(i)){
                        //cout<<i<<endl;
                        cnt++;
                    }
                }
            }
        }
        cout<<"Case "<<caseno++<<": "<<cnt<<endl;
    }

    return 0;
}
