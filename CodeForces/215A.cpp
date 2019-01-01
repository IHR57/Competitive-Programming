#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 60
using namespace std;

int main()
{
    int n, m, a[MAX], b[MAX];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int Ratio, maxRatio = 0;
    for(int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j--){
            if(b[j] % a[i] == 0){
                Ratio = b[j] / a[i];
                if(Ratio > maxRatio)
                    maxRatio = Ratio;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[j] % a[i] == 0){
                Ratio = b[j] / a[i];
                if(Ratio == maxRatio)
                    count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
