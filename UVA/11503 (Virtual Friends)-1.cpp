#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#define MAX 100005
using namespace std;

string first, second;
int parent[MAX], Size[MAX];


void init()
{
    for(int i = 0; i < MAX; i++){
        parent[i] = i;
        //setSize[i] = 1;
        Size[i] = 1;
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

int unionSet(int i, int j)
{
    int x = findSet(i);
    int y = findSet(j);

    if(x != y){     //which set has maximum element
        if(Size[x] > Size[y]){
            Size[x] += Size[y];
            parent[y] = x;
            return Size[x];
        }
        Size[y] += Size[x];
        parent[x]  = y;
        return Size[y];
    }

    return Size[x];
}

int main()
{
    int test, a, n, b;

    cin>>test;

    while(test--){
        cin>>n;

        init();
        int count = 0;
        map<string, int> M;
        for(int i = 0; i < n; i++){
            cin>>first>>second;
            a = M[first];

            if(a == 0){
                M[first] = ++count;
                a = count;
                //cout<<a<<endl;
            }

            b = M[second];

            if(b == 0){
                M[second] = ++count;
                b = count;
                //cout<<b<<endl;
            }
            cout<<unionSet(a, b)<<endl;
        }
    }

     return 0;
}
