#include <iostream>
#include <cstdio>
#define MAX 100005
using namespace std;

int main()
{
    int n, k, m, arr[MAX], counter[MAX] = {0}, value;

    scanf("%d %d %d", &n, &k, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        counter[arr[i] % m]++;
    }

    int Max = -1;
    for(int i = 0; i < MAX; i++){
        if(counter[i] > Max){
            Max = counter[i];
            value = i;
        }
    }

    if(Max < k){
        printf("No\n");
    }
    else{
        int count = 0;
        printf("Yes\n");
        for(int i = 0; i < n; i++){
            if(arr[i] % m == value){
                count++;
                if(count <= k)
                    printf("%d ", arr[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
