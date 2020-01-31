#include <iostream>
#define MAX 100005
using namespace std;

typedef long long ll;

ll temp[MAX];

void mergeSort(ll num[], int l, int r)
{
    if(l == r)
        return;
    int mid = (l + r) >> 1;

    mergeSort(num, l, mid);
    mergeSort(num, mid + 1, r);

    int i, j, k;

    for(int i = l, j = mid + 1, k = l; k <= r; k++){
        if(i == mid + 1)
            temp[k] = num[j++];
        else if(j == r + 1)
            temp[k] = num[i++];
        else if(num[i] < num[j]){
            temp[k] = num[i++];
        }
        else{
            temp[k] = num[j++];
        }
    }
    for(int k = l; k <= r; k++){
        num[k] = temp[k];
    }
}

int main()
{

    return 0;
}
