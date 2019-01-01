#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100005
using namespace std;

int main()
{
    int x;
    int F[MAX];

    F[0] = 0, F[1] = 1, F[2] = 2;

    for(int i = 3; i < MAX; i++){
        if(i % 2 != 0){
            F[i] = 0;
        }
        else{
            F[i] = F[2] + F[i / 2] ;
        }
    }

    scanf("%d", &x);
    printf("%d\n", F[x]);

    return 0;
}
