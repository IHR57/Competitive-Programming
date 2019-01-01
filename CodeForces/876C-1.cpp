#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

int n;

bool checkValue(int x)
{
    int sum = x;

    while(x != 0){
        int t = x % 10;
        sum += t;
        x = x / 10;
    }

    //cout<<sum<<endl;
    if(sum == n)
        return true;
    return false;
}

int main()
{
    vector<int> v;

    scanf("%d", &n);

    int count = 0;

    int temp = n;

    for(int i = 1; i <= 90; i++){
        if(checkValue(temp)){
            count++;
            v.push_back(temp);
        }
        temp--;
        if(temp <= 0)
            break;
    }

    if(count){
        printf("%d\n", count);

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            printf("%d\n", v[i]);
        }
    }
    else
        printf("0\n");

    return 0;
}
