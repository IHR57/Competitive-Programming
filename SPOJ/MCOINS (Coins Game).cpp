#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int state[MAX];

int main()
{
    int k, l, m, arr[55];

    scanf("%d %d %d", &k, &l, &m);

    state[1] = 1, state[k] = 1, state[l] = 1;

    for(int i = 2; i < MAX; i++){
        if(state[i] != 1){
            int flag = 0;
            if(state[i-1] == 0)
                flag = 1;
            if(i - k > 0){
                if(state[i-k] == 0){
                    flag = 1;
                }
            }
            if(i - l > 0){
                if(state[i-l] == 0)
                    flag = 1;
            }

            if(flag){
                state[i] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < m; i++){
        (state[arr[i]] == 1) ? printf("A") : printf("B");
    }
    printf("\n");

    return 0;
}
