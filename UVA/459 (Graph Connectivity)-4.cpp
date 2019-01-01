#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAX 50
using namespace std;

int parent[MAX], Rank[MAX];
int numofDisjoint;

void init()
{
    for(int i = 0; i < MAX; i++){
        parent[i] = i;
        Rank[i] = 1;
    }
}

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);      //find the representative
}

void unionSet(int i, int j)
{
    int u = findSet(i);
    int v = findSet(j);

    if(u != v){
        numofDisjoint--;
        parent[u] = v;
    }
}

int main()
{
   int test, n;
   string s;

   scanf("%d\n\n", &test);

   for(int tc = 1; tc <= test; tc++){
        init();             //initialize rank and parent
        getline(cin, s);
        n = s[0] - 'A' + 1;
        numofDisjoint = n;

        while(1){
            if(!getline(cin, s) || s.empty())
                break;
            int x = s[0] - 'A';
            int y = s[1] - 'A';

            unionSet(x, y);
        }

        if(tc != 1)    printf("\n");

        printf("%d\n", numofDisjoint);

   }

   return 0;
}
