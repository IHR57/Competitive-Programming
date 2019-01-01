#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

int main()
{
    int n, pages[10], sum;

    cin>>n;

    sum = 0;
    int index = 0;

    for(int i = 0; i < 7; i++){
        cin>>pages[i];
    }
    for(int i = 0; i < 7; i++){
        sum += pages[i];
        if(sum >= n){
            index = i + 1;
            break;
        }
    }

    if(index){
        printf("%d\n", index);
    }
    else{
        int j = 0;
        while(sum < n){
            int tmp = j % 7;
            sum += pages[tmp];
            if(sum >= n){
                index = tmp + 1;
                break;
            }
            j++;
        }
        printf("%d\n", index);
    }

    return 0;
}
