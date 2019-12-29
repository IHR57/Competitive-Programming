#include <bits/stdc++.h>
#define MAX 50
using namespace std;

const int inf = 1<<28;

int dirx[] = {0, 0, 1, 0, 0, -1};
int diry[] = {0, 1, 0, 0, -1, 0};
int dirz[] = {1, 0, 0, -1, 0, 0};

struct data{
    int x, y, z;
};

int isForbidden[26][26][26], dist[26][26][26], visited[26][26][26];
int ans;
char start[5], finish[5];

void bfs()
{
    memset(visited, 0, sizeof(visited));

    visited[start[0]-'a'][start[1]-'a'][start[2]-'a'] = 1;
    queue<data> q;
    q.push(data{start[0]-'a', start[1]-'a', start[2]-'a'});
    dist[start[0]-'a'][start[1]-'a'][start[2]-'a'] = 0;

    while(!q.empty()){
        data u = q.front();
        q.pop();

        if(u.x == finish[0]-'a' && u.y == finish[1]-'a' && u.z == finish[2]-'a'){
            ans = dist[u.x][u.y][u.z];
            return;
        }
        for(int k = 0; k < 6; k++){
            int tx = (u.x + dirx[k]) % 26;
            int ty = (u.y + diry[k]) % 26;
            int tz = (u.z + dirz[k]) % 26;

            if(tx < 0)  tx += 26;
            if(ty < 0)  ty += 26;
            if(tz < 0)  tz += 26;

            if(!isForbidden[tx][ty][tz] && !visited[tx][ty][tz]){
                visited[tx][ty][tz] = 1;
                dist[tx][ty][tz] = dist[u.x][u.y][u.z] + 1;
                q.push(data{tx, ty, tz});
            }
        }
    }
}

int main()
{
    int test, caseno = 1, q;
    char str1[MAX], str2[MAX], str3[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%s", start);
        scanf("%s", finish);
        scanf("%d", &q);

        memset(isForbidden, 0, sizeof(isForbidden));

        for(int i = 0; i < q; i++){
            scanf("%s %s %s", str1, str2, str3);
            int len1  = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);
            for(int j = 0; j < len1; j++){
                for(int k = 0; k < len2; k++){
                    for(int l = 0; l < len3; l++){
                        isForbidden[str1[j]-'a'][str2[k]-'a'][str3[l]-'a'] = 1;
                    }
                }
            }
        }

        ans = inf;
        bfs();

        if(ans == inf || isForbidden[start[0]-'a'][start[1]-'a'][start[2]-'a']){
            printf("Case %d: -1\n", caseno++);
        }
        else
            printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}
