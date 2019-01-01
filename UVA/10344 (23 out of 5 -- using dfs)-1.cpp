#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int arr[20], used[100], result, flag;

void depthFirst(int pos, int sum)
{
    if(pos == 5 && sum == 23){      //base case
        flag = 1;
        return;
    }

    for(int i = 0; i < 5; i++){
        if(!used[i]){
            used[i] = 1;
            depthFirst(pos + 1, sum + arr[i]);  // 3 recursive call for + * -
            depthFirst(pos + 1, sum * arr[i]);
            depthFirst(pos + 1, sum - arr[i]);
            used[i] = 0;
        }
    }
}

int main()
{
    int fst, snd, trd, frth, ffth;
    while(scanf("%d %d %d %d %d", &fst, &snd, &trd, &frth, &ffth) == 5){
        if(fst == 0 && snd == 0 && trd == 0 && frth == 0 && ffth == 0)
            break;
        arr[0] = fst, arr[1]  = snd, arr[2] = trd, arr[3] = frth, arr[4] = ffth;

        //memset(used, 0, sizeof(used));
        flag = 0;       //set flag zero

        for(int i = 0; i < 5; i++){
            used[i] = 1;
            depthFirst(1, arr[i]);
            used[i] = 0;
        }

        if(flag)            //if we find result = 23
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
