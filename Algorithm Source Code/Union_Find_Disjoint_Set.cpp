#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int parent[MAX], Rank[MAX];

void init()
{
    for(int i = 0; i < MAX; i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findSet(int x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
    if(!isSameSet(i, j)){
        int x = findSet(i);
        int y = findSet(j);

        if(Rank[x] > Rank[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            if(Rank[x] == Rank[y])
                Rank[y]++;
        }
    }
}

int main()
{
    init();
    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(2, 3);
    unionSet(4, 5);
    unionSet(5, 6);
    unionSet(8, 9);

    cout<<Rank[1]<<" "<<Rank[4]<<" "<<Rank[8]<<endl;
    cout<<isSameSet(3, 4)<<endl;
    cout<<isSameSet(4, 6)<<endl;

    return 0;
}
