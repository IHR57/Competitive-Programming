#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000005
using namespace std;

int main()
{
    int flag, test, caseno = 1, n, value;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        flag = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &value);
            if(value % 3 != 0)
                flag = 0;
        }

        if(!flag){
            printf("Case #%d: No\n", caseno++);
        }
        else{
            printf("Case #%d: Yes\n", caseno++);
        }
    }

    return 0;
}
