//Problem ID: HackerRank - bear-and-steady-gene (Bear and Steady Gene)
//Programmer: IQBAL HOSSAIN 	Description: String
//Date: 11/08/19
//Problem Link: https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define MOD 1000000007
#define MAX 500005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int cs[MAX][4], tot[4];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;
    string str;

    cin>>n;
    cin>>str;
    map<char, int> MP;
    MP['A'] = 0, MP['C'] = 1, MP['G'] = 2, MP['T'] = 3;

    for(int i = 1; i <= n; i++){
        cs[i][MP[str[i-1]]] = cs[i-1][MP[str[i-1]]] + 1;
        for(int j = 0; j < 4; j++){
            if(j != MP[str[i-1]])
                cs[i][j] = cs[i-1][j];
        }
    }

    int req = n / 4;
    int low = 0, high = n, mid, ans = -1;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        bool possible = false;
        for(int i = 1; i <= n - mid + 1; i++){
            bool flag = true;
            for(int j = 0; j < 4; j++){
                tot[j] = (cs[n][j] - cs[i+mid-1][j]) + (cs[i-1][j] - cs[0][j]);
                //cout<<tot[j]<<endl;
                if(tot[j] > req){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int rem = mid;
                for(int j = 0; j < 4; j++){
                    tot[j] += (req - tot[j]);
                    rem -= (req - tot[j]);
                }
                if(rem >= 0){
                    possible = true;
                    break;
                }
            }
        }
        if(possible){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
