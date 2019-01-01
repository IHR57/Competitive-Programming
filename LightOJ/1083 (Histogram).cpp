#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 30010
using namespace std;

int findMaxArea(int arr[], int n)       //return largest area of histogram
{
    int area[MAX], temp;

    for(int i = 0; i < n; i++)
        area[i] = 1;        //initial area of each histogram
    stack<int> st;

    //calculating number of left histogram that satisfy the condition
    for(int i = 0; i < n; i++){
        while(!st.empty()){
            if(arr[st.top()] >= arr[i]){
                st.pop();
            }
            else
                break;
        }

        if(st.empty()){
            temp = -1;
        }
        else
            temp = st.top();
        area[i] += i - temp - 1;
        st.push(i);
    }

    while(!st.empty())
        st.pop();       //clearing stack as we have to use it again

    //calculating right histogram

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty()){
            if(arr[st.top()] >= arr[i]){
                st.pop();
            }
            else
                break;
        }

        if(st.empty()){
            temp = n;
        }
        else
            temp = st.top();
        area[i] += temp - i - 1;
        st.push(i);
    }

    int Max = 0;

    for(int i = 0; i < n; i++){
        if(area[i] * arr[i] >= Max)
            Max = area[i] * arr[i];
    }

    return Max;
}

int main()
{
    int test, cases = 1, n, data[MAX];

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
        }

        int result = findMaxArea(data, n);

        printf("Case %d: %d\n", cases++, result);
    }

    return 0;
}
