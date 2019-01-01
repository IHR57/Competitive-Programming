#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 1 << 28;

int main()
{
    int n, arr[110];

    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    int Min = INF, idx1, idx2, index;

    //if(n == 2){
      //  printf("1 2\n");
    //}
   // else{
        for(int i = 1; i <= n; i++){
            index = (i + 1) % (n + 1);
            if(!index)
                index = 1;
            int ans = abs(arr[i] - arr[index]);

            if(ans < Min){
                Min = ans;
                idx1 = i;
                idx2 = (i + 1) % (n + 1);
                if(!idx2)
                    idx2 = 1;
            }
        }

        printf("%d %d\n", idx1, idx2);
    //}

    return 0;
}
