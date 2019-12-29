//Problem ID: Kattis - knightsearch (Knight Search)
//Programmer: IQBAL HOSSAIN 	Description: BFS
//Date: 02/08/19
//Problem Link: https://open.kattis.com/problems/knightsearch
#include <bits/stdc++.h>
#define MAX 105
#define mp make_pair
#define MOD 1000000007
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int fx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
int fy[] = { -1,  1, -2,  2, -2,  2, -1,  1 };

char cell[MAX][MAX];
int n, dist[MAX][MAX];
string res = "ICPCASIASG";

bool bfs(int sx, int sy)
{	
	memset(dist, 0, sizeof(dist));
	queue<ii> q;
	q.push(mp(sx, sy));

	int Max = 0;
	while(!q.empty()){
		ii u = q.front();
		q.pop();

		for(int i = 0; i < 8 ; i++){
			int tx = u.first + fx[i];
			int ty = u.second + fy[i];
			if(tx >= 0 && tx < n && ty >= 0 && ty < n && cell[tx][ty] == res[dist[u.first][u.second] + 1]){
				dist[tx][ty] = dist[u.first][u.second] + 1;
				q.push(mp(tx, ty));
				Max = max(Max, dist[tx][ty]);
			}
		}
	}
	if(Max >= 9)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	string str;

	cin>>n;
	cin>>str;

	for(int i = 0; i < (n * n); i++){
		cell[i/n][i%n] = str[i];
	}

	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			if(cell[i][j] == 'I'){
				if(bfs(i, j)){
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}

	cout<<"NO"<<endl;

	return 0;
}