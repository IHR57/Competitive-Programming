//Problem ID: HackerRank - Lilys-homework (Lily's Homework)
//Programmer: IQBAL HOSSAIN 	Description: Sorting
//Dat: 10/08/19
//Problem Link: https://www.hackerrank.com/challenges/lilys-homework/problem
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

int arr[MAX], temp[MAX], pos[MAX], t[MAX], org[MAX];
int n;

int solve()
{
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] != t[i]){
			cnt++;
			pos[arr[i]] = pos[t[i]];
			swap(arr[i], arr[pos[t[i]]]);
		}
	}

	return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    cin>>n;

    for(int i = 0; i < n; i++){
    	cin>>arr[i];
    	temp[i] = arr[i];
    }

    sort(temp, temp + n);

    for(int i = 0; i < n; i++){
    	int idx = lower_bound(temp, temp + n, arr[i]) - temp;
    	arr[i] = idx;
    	pos[idx] = i;
    	t[i] = idx;
    	org[i] = arr[i];
    }

    sort(t, t + n);
    int res = solve();

    for(int i = 0; i < n; i++){
    	arr[i] = org[i];
    	pos[arr[i]] = i;
    }

    reverse(t, t + n);
    res = min(res, solve());

    cout<<res<<endl;

    return 0;
}
