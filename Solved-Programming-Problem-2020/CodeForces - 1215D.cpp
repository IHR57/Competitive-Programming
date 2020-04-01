//Date: 13/03/2020
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    string str;

    cin>>n;
    cin>>str;

    int lsum = 0, rsum = 0, lcnt = 0, rcnt = 0;

    for(int i = 0; i < n; i++){
        if(i < n / 2){
            if(str[i] == '?')
                lcnt++;
            else
                lsum += (str[i] - 48);
        }
        else{
            if(str[i] == '?')
                rcnt++;
            else
                rsum += (str[i] - 48);
        }
    }

    if(lsum == rsum){
        if(lcnt == rcnt){
            cout<<"Bicarp"<<endl;
        }
        else{
            cout<<"Monocarp"<<endl;
        }
    }
    else if((lsum > rsum && lcnt > rcnt) || (lsum < rsum && lcnt < rcnt)){
        cout<<"Monocarp"<<endl;
    }
    else{
        if(lsum < rsum){
            swap(lsum, rsum);
            swap(lcnt, rcnt);
        }
        int tcnt = rcnt - lcnt;
        if(rsum + (tcnt / 2) * 9 == lsum){
            cout<<"Bicarp"<<endl;
        }
        else{
            cout<<"Monocarp"<<endl;
        }
    }

    return 0;
}
