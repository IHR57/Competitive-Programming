#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1<<28;
int Min;

bool smallestSubArray(int arr[], int n, int result)
{
    deque<pii> dq;

    int sum = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        dq.push_back(make_pair(arr[i], i));
        sum += arr[i];
        while(sum >= result){
            int Size = dq.back().second - dq.front().second;
            //cout<<dq.back().second<<" "<<dq.front().second<<endl;
            if(Size < Min)
                Min = Size;
           // cout<<sum<<endl;
            sum -= dq.front().first;
            dq.pop_front();
            flag = true;
        }
    }

    return flag;
}

int main()
{
    int data[100005], n, s;

    while(scanf("%d %d", &n, &s) == 2){
        for(int i = 0; i < n; i++){
            scanf("%d", &data[i]);
        }
        Min = INF;
        bool result = smallestSubArray(data, n, s);
        if(result)
            printf("%d\n", Min+1);
        else
            printf("%d\n", 0);
    }

    return 0;
}
