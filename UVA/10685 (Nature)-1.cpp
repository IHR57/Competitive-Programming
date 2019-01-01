#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define MAX 5005
using namespace std;

int parent[MAX], setSize[MAX];

int findSet(int x)      //find predecessor or representative
{
    if(parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

bool isSameSet(int i, int j)        //check if both element are in same set
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
    int x = findSet(i);
    int y = findSet(j);

    if(x != y){
        parent[x] = y;
        setSize[y] += setSize[x];
    }
}

int main()
{
    int n, relation, Max;
    string first, second;

    while(cin>>n>>relation){
        if(n == 0 && relation == 0)
            break;
        map<string, int> M;

        Max = 0;

        for(int i = 0; i < n; i++){
            cin>>first;
            M[first] = i;
            parent[i] = i;
            setSize[i] = 1;
        }

        for(int i = 0; i < relation; i++){
            cin>>first>>second;
            int a = M[first];
            int b = M[second];

            unionSet(a, b);
        }

        for(int i = 0; i < n; i++){
            if(setSize[i] > Max){
                Max = setSize[i];
            }
        }

        cout<<Max<<endl;
    }

    return 0;
}
