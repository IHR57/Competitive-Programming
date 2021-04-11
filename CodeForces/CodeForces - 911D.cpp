/*
Template for vjudge.net

    Author: Iqbal Hossain Rasel
    CodeForces: Psychedelic
    AtCoder   : IHR57
    TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 2005
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

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

    int n, m, l, r;

    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }    

    int cntInv = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                cntInv++;
            }
        }
    }

    bool isOdd = (cntInv & 1);
    cin>>m;

    for(int i = 0; i < m; i++) {
        cin>>l>>r;
        if(((r - l + 1) >> 1) & 1)
            isOdd ^= 1;
        (isOdd) ? cout<<"odd"<<endl : cout<<"even"<<endl;
    }

    return 0;
}