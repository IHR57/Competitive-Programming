//Problem ID: HackerRank - mandragora (Mandragora Forest)
//Programmer: IQBAL HOSSAIN     Description: Greedy/DP
//Date: 09/08/19
//Problem Link: https://www.hackerrank.com/challenges/mandragora/problem
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

int h[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, test;

    cin>>test;
    priority_queue<int, vector<int>, greater<int> > pq;

    while(test--){
        cin>>n;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin>>h[i];
            sum += (ll) h[i];
            pq.push(h[i]);
        }
        ll k = 1;
        ll Max = (sum * k);
        while(!pq.empty()){
            sum -= pq.top();
            pq.pop();
            k++;
            Max = max(Max, (sum * k));
        }

        cout<<Max<<endl;
    }

    return 0;
}
