#include <bits/stdc++.h>
#define MAX 205
#define mp make_pair
#define MOD 1000000007
using namespace std;
typedef long long ll;

char cell[MAX][MAX];
int r, c, dist[MAX][MAX], visited[MAX][MAX];
bool isOut = false, isLost = false;

void bfs(int sx, int sy)
{
	memset(dist, -1, sizeof(dist));
	dist[sx][sy] = 0;
	queue<pair<int, int> > q;
	q.push(mp(sx, sy));
	visited[sx][sy] = 1;

	while(!q.empty()){
		pair<int, int> u = q.front();
		int i = u.first, j = u.second;
		q.pop();

		int tx, ty;
		if(cell[i][j] == 'E'){
			tx = i, ty = j + 1;
			if(ty >= c){
				isOut = true;
				return;
			}
			if(visited[tx][ty]){
				isLost = true;
				return;
			}
			dist[tx][ty] = dist[i][j] + 1;
			q.push(mp(tx, ty));
			visited[tx][ty] = 1;
		}
		else if(cell[i][j] == 'W'){
			tx = i, ty = j - 1;
			if(ty < 0){
				isOut = true;
				return;
			}
			if(visited[tx][ty]){
				isLost = true;
				return;
			}
			dist[tx][ty] = dist[i][j] + 1;
			q.push(mp(tx, ty));
			visited[tx][ty] = 1;
		}
		else if(cell[i][j] == 'N'){
			tx = i - 1, ty = j;
			if(tx < 0){
				isOut = true;
				return;
			}
			if(visited[tx][ty]){
				isLost = true;
				return;
			}
			dist[tx][ty] = dist[i][j] + 1;
			q.push(mp(tx, ty));
			visited[tx][ty] = 1;
		}
		else if(cell[i][j] == 'S'){
			tx = i + 1, ty = j;
			if(tx >= r){
				isOut = true;
				return;
			}
			if(visited[tx][ty]){
				isLost = true;
				return;
			}
			dist[tx][ty] = dist[i][j] + 1;
			q.push(mp(tx, ty));
			visited[tx][ty] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin>>r>>c;
	int dx, dy;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>>cell[i][j];
			if(cell[i][j] == 'T'){
				dx = i, dy = j;
			}
		}
	}

	bfs(0, 0);
	if(isOut){
		cout<<"Out"<<endl;
	}
	else if(isLost){
		cout<<"Lost"<<endl;
	}
	else{
		cout<<dist[dx][dy]<<endl;
	}

	return 0;
}