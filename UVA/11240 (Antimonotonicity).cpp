#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>
#define MAX 30005
using namespace std;

int main()
{
    int n, a[MAX], test;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        int count = 1;

        for(int i = 1; i < n; i++){
            if(count % 2 == 0 && a[i] > a[i-1]){
                count++;
            }
            else if(count % 2 == 1 && a[i] < a[i-1]){
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
