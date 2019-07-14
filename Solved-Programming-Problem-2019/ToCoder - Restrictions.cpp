#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

class Restrictions
{
	public:
		vector <int> exist(int n, int m, vector <int> type, vector <int> l, vector <int> r, vector <int> val)
		{
			vector<int> res(n, -1);
			int limL[n + 5], limR[n + 5];
			memset(limL, -1, sizeof(limL));
			memset(limR, -1, sizeof(limR));
			for(int i = 0; i < m; i++){
				if(type[i] == 1){
					for(int j = l[i]; j <= r[i]; j++){
						if(limL[j] == -1){
							res[j] = val[i];
							limR[j] = val[i];
						}
						else if(limL[j] < val[i]){
							return {-1};
						}
					}
				}
				else{
					for(int j = l[i]; j <= r[i]; j++){
						if(limR[j] == -1){
							res[j] = 0;
							limL[j] = val[i];
						}
						else if(limR[j] > val[i]){
							return {-1};
						}
					}
				}
			}

			return res;
		}

};