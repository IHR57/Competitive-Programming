#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[200], index[200], n;

bool isAscending()  //check is values are sorted in ascending order?
{
    bool flag  = true;
    for(int i = 0; i < n-1; i++){
        if(arr[i+1] < arr[i]){
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    int test, cases = 1;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        int count = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            index[arr[i]] = i;      //index of the value 1 to n
        }
        for(int i = n; i >= 1; i--){
            if(!isAscending()){
                if(arr[i-1] != arr[index[i]]){
                    swap(arr[i-1], arr[index[i]]);      //swap if the hold the condition
                    count++;
                }
                for(int j = 0; j < n; j++){
                    index[arr[j]] = j;      //array is changed so we need to change the index
                }
               // printf("\n");
            }
            else{
                break;
            }
        }
        printf("Case %d: %d\n", cases++, count);
    }

    return 0;
}
