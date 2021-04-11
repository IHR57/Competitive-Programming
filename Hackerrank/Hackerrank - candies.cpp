#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int n, arr[MAX];

void input()
{
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }
}

void solve()
{
  vector<int> pref(n + 1, 1), suff(n + 1, 1);
  for(int i = 1; i < n; i++){
    if(arr[i] > arr[i-1])
      pref[i] = pref[i-1] + 1;
  }
  for(int i = n - 2; i >= 0; i--){
    if(arr[i] > arr[i+1])
      suff[i] = suff[i+1] + 1;
  }

  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += (ll) max(suff[i], pref[i]);
  }

  cout<<ans<<endl;

}

int main() 
{
  input();
  solve();
}