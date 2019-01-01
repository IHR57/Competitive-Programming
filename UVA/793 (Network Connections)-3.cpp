#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#define MAX 1000
using namespace std;

int n, p[MAX], Rank[MAX];

void init()     //initialization
{
    for(int i = 1; i <= n; i++){
        p[i] = i;
        Rank[i] = 0;
    }
}
int findSet(int x)      //find the representative of x
{
    if(p[x] == x)
        return x;
    return p[x] = findSet(p[x]);
}

bool isConnected(int i, int j)      //if two elements are connected
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
    if(!isConnected(i, j))
    {
        int x = findSet(i);
        int y = findSet(j);

        if(x == y)
            return;

        if(Rank[x] > Rank[y]){
            p[y] = x;
        }
        else{
            p[x] = y;
            if(Rank[x] == Rank[y])
                Rank[y]++;
        }
    }
}

int main()
{
    int test, a, b;
    char ch;
    string str;

    scanf("%d", &test);

    while(test--){
        scanf("\n%d\n", &n);

        init();
        int successful = 0, unsuccessful = 0;       //number of successful and unsuccessful query

        while(1){
            if(!getline(cin, str) || str.empty())   break;      //if we find blank line
            sscanf(str.c_str(), "%c %d %d", &ch, &a, &b);

            if(ch == 'c'){      //c for connect
                unionSet(a, b);
            }
            else if(ch == 'q'){     //q for query
                bool flag = isConnected(a, b);  //return true if it is connected
                if(flag)
                    successful++;       //if true increment successful query
                else
                    unsuccessful++;
            }
        }

        printf("%d,%d\n", successful, unsuccessful);
        if(test)
            printf("\n");
    }

    return 0;
}
