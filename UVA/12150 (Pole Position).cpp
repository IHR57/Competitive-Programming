#include <bits//stdc++.h>
using namespace std;

int main()
{
    int n, carNumber, position, *data, value, flag;

    while(cin>>n && n != 0){

        int data[10007] = {};

        memset(data, 0, sizeof(data));
        flag = 0;       //initialize flag with true

        for(int i = 0; i < n; i++){
            cin>>carNumber>>position;
            value = i + position;

            if(value >= n || value < 0){
                flag = 1;       //if cross the limit
                //continue;
            }
            if(data[value] && !flag){
                flag = 1;
            }
            if(flag)
                continue;
            data[value] = carNumber;
        }

        if(flag)
            printf("-1\n");
        else{
            for(int i = 0; i < n-1; i++){
                printf("%d ", data[i]);
            }
            printf("%d\n", data[n-1]);
        }
    }

    return 0;
}
