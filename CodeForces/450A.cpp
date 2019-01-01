#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

struct data
{
    int index, value;
};

int main()
{
    int n, m;
    queue<data> q;

    scanf("%d %d", &n, &m);

    int x;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        data val;
        val.index = i;
        val.value = x;
        q.push(val);
    }

    data result;

    while(!q.empty()){
        result = q.front();
        q.pop();
        if(result.value > m){       //if the child do not satisfies
            result.value -= m;
            q.push(result);     //again the push it into queue
        }
    }

    printf("%d\n", result.index);       //index of last child

    return 0;
}
