#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define MAX 100005
using namespace std;

vector<int> v;
int L[MAX], I[MAX], lisSequence[MAX];
const int INF = 1 << 28;

int LIS()
{
    int length = v.size();

    for(int i = 1; i <= length; i++){
        I[i] = INF;
    }
    I[0] = -INF;        //set 0th element -INF

    int low, high, mid, lisLength = 0;

    for(int i = 0; i < length; i++){
        low = 0;
        high = lisLength;

        //binary search to find correct position of the i'th element
        while(low <= high){
            mid = (low + high) >> 1;
            if(I[mid] < v[i]){
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        I[low] = v[i];      //insert value in found position

        if(low > lisLength)
            lisLength = low;
        L[i] = low;     //fill L[] array
    }

    return lisLength;       //return maximum length found
}

void findSequence(int maxLength)
{
    int i = 0;
    int length = v.size();

    for(int j = 1; j < length; j++){
        if(L[j] >= L[i])
            i = j;
    }

    int top = L[i] - 1;
    lisSequence[top] = v[i];
    top--;

    for(int j = i - 1; j >= 0; j--){        //scan from backward
        if(v[j] < v[i] && L[j] == L[i] - 1){
            i = j;
            lisSequence[top] = v[i];
            top--;
        }
    }

    for(int i = 0; i < maxLength; i++){
        printf("%d\n", lisSequence[i]);
    }
}

int main()
{
    int n;

    while(cin>>n){
        v.push_back(n);
    }

    int longest = LIS();        //longest increasing sequence

    printf("%d\n-\n", longest);
    findSequence(longest);     //print solution

    return 0;
}
