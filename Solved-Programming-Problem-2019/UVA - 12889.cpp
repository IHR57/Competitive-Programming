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

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        set<int> s;
        int cnt = 0, cnt1 = 0, sum = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] == 0)
                cnt++;
            else if(arr[i] == 1)
                cnt1++;
            else
                s.insert(arr[i]);
        }
        if(n == 1 || cnt == n || cnt1 == n){
            cout<<"Better luck next time!"<<endl;
        }
        else if(cnt1 > 0 || cnt > 0)
            cout<<"Happy Birthday Tutu!"<<endl;
        else{
            //cout<<n - cnt - cnt1<<endl;
            if(s.size() == 1){
                cout<<"Better luck next time!"<<endl;
            }
            else{
                cout<<"Happy Birthday Tutu!"<<endl;
            }
        }
    }

    return 0;
}
