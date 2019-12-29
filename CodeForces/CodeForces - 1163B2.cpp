//Problem ID: CodeForces - 1163B2 (Cat Party)
//Programmer: IQBAL HOSSAIN 	Description: Data Structure/Implementation
//Date: 21/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int vis[MAX], counter[MAX], u[MAX];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;

	cin>>n;
	int ans = 0;
	set<int> s;

	for(int i = 0; i < n; i++){
		cin>>u[i];
		vis[u[i]]++;
		counter[vis[u[i]]]++;
		if(vis[u[i]] > 1){
			counter[vis[u[i]]-1]--;
			if(counter[vis[u[i]]-1] <= 0){
				s.erase(vis[u[i]]-1);
			}
		}
		s.insert(vis[u[i]]);
		if(s.size() == 1){
			if(*s.begin() == 1 || counter[*s.begin()] <= 1)
				ans = i;
		}
		else if(s.size() == 2){
			if(counter[*s.begin()] == 1 || counter[*s.rbegin()] == 1){
				if(*s.begin() == 1 && counter[*s.begin()] == 1)
					ans = i;
				else if(*s.begin() + 1 == *s.rbegin() && counter[*s.rbegin()] == 1){
					ans = i;
				}
			}
		}
		//cout<<s.size()<<endl;

	}

	cout<<ans + 1<<endl;

	return 0;
}