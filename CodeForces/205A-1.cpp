#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100005
using namespace std;

const long long int INF = 1 << 31;

int main()
{
    long long int data[MAX], Min;
    int index, n;
    bool idx[MAX];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lld", &data[i]);
    }

    Min = data[0];

    for(int i = 1; i < n; i++){
        if(data[i] < Min){
            Min = data[i];
            index = i + 1;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        if(data[i] == Min){
            count++;
            if(count >= 2)
                break;
        }
    }

    if(count == 2)
        printf("Still Rozdil\n");
    else
        printf("%d\n", index);

    return 0;
}
