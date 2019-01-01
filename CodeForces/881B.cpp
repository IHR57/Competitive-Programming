//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int Mark[MAX];

int convert(int x, int y, int z)
{
    return ((100 * x) + (10 * y) + z);
}
int main()
{
    int a[20], b[20], c[20];
    int n, idx;

    scanf("%d", &n);

    if(n == 1){
        for(int i = 0; i < 6; i++){
            scanf("%d", &a[i]);
            Mark[a[i]] = 1;
        }

        for(int i = 1; i < 1000; i++){
            if(!Mark[i]){
                idx = i;
                break;
            }
        }
        printf("%d\n", idx - 1);
    }
    else if(n == 2){
        for(int i = 0; i < 6; i++){
            scanf("%d", &a[i]);
            Mark[a[i]] = 1;
        }
        for(int i = 0; i < 6; i++){
            scanf("%d", &b[i]);
            Mark[b[i]] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 6; j++){
                int value1 = a[i] * 10 + b[j];
                int value2 = b[j] * 10 + a[i];
                Mark[value1] = 1;
                Mark[value2] = 1;
            }
        }

        for(int i = 1; i < 1000; i++){
            if(!Mark[i]){
                idx = i;
                break;
            }
        }
        printf("%d\n", idx - 1);
    }

    else if(n == 3){
        for(int i = 0; i < 6; i++){
            scanf("%d", &a[i]);
            Mark[a[i]] = 1;
        }
        for(int i = 0; i < 6; i++){
            scanf("%d", &b[i]);
            Mark[b[i]] = 1;
        }
        for(int i = 0; i < 6; i++){
            scanf("%d", &c[i]);
            Mark[c[i]] = 1;
        }

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                int value1 = a[i] * 10 + b[j];
                int value2 = b[j] * 10 + a[i];
                Mark[value1] = 1;
                Mark[value2] = 1;
            }
        }

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                int value1 = b[i] * 10 + c[j];
                int value2 = c[j] * 10 + b[i];
                Mark[value1] = 1;
                Mark[value2] = 1;
            }
        }

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                int value1 = a[i] * 10 + c[j];
                int value2 = c[j] * 10 + a[i];
                Mark[value1] = 1;
                Mark[value2] = 1;
            }
        }

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k < 6; k++){
                    int value1 = a[i] * 100 + b[j] * 10 + c[k];
                    int value2 = c[k] * 100 + b[j] *10 + a[i];
                    Mark[value1] = 1;
                    Mark[value2] = 1;
                }
            }
        }

        for(int i = 1; i < 1000; i++){
            if(!Mark[i]){
                idx = i;
                break;
            }
        }

        printf("%d\n", idx - 1);

    }

    return 0;
}
