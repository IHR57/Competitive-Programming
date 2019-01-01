#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define pb push_back
#define MAX 300005
using namespace std;

typedef long long ll;

int blockSize, arr[MAX];
int block[560][560];

void init(int n)
{
    for(int i = 0; i < n; i++){
        block[i/blockSize][i%blockSize] = arr[i];
    }
}

void update(int idx, int value)
{
    arr[idx] = value;
    block[idx/blockSize][idx%blockSize] = value;
}

int query(int low, int high, int value)
{
    int count = 0;
    int cl = low / blockSize, cr = high / blockSize;

    if(cl == cr){                                //if two range are in same block
        for(int i = low; i <= high; i++){
            if(arr[i] < value)
                count++;
        }
    }
    else{
        int End = (cl + 1) * blockSize - 1;
        for(int i = low; i <= End; i++){
            if(arr[i] < value)
                count++;
        }
        for(int i = cl + 1; i <= cr - 1; i++){
            sort(block[i] , block[i]+blockSize);
            int t = lower_bound(block[i] , block[i]+blockSize, value) - block[i];
            count += t;
        }
        for(int i = cr * blockSize; i <= high; i++){
            if(arr[i] < value)
                count++;
        }
    }

    return count;
}

int main()
{
    int n, x, y, value, idx, maxValue, m;

    while(scanf("%d %d %d", &n, &m, &maxValue) == 3){       //number of element and query and maximum value in the array

        blockSize = (int) sqrt(n + .0) + 1;

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        init(n);

        for(int i = 0; i < m; i++){
            scanf("%d %d %d %d", &x, &y, &value, &idx);     //range x, y and change value at arr[idx]
            x--, y--, idx--;
            int k = query(x,  y, value);
            update(idx, maxValue*k / (y - x + 1));
        }

        for(int i = 0; i < n; i++){
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}
