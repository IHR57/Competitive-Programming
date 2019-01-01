#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX];

    cin>>str;

    int len = strlen(str), Greater = 0, smaller = 0, minPos = 10000000, maxPos = -10000000;

    int lastDigit = str[len-1] - 48, count = 0;

    for(int i = 0; i < len - 1; i++){
        int temp = str[i] - 48;
        if(temp % 2 == 0 && temp < lastDigit){
            smaller++;
            count++;
            if(count == 1)
                minPos = i;
        }
        else if(temp % 2 == 0 && temp > lastDigit){
            Greater++;
            if(temp > lastDigit)
                maxPos = i;
        }
    }

    //check condition
    if(smaller == 0 && Greater == 0){       //no even number
        cout<<-1<<endl;
    }
    else if(smaller == 0 && Greater != 0){
        swap(str[len-1], str[maxPos]);
        cout<<str<<endl;
    }
    else if(Greater == 0 && smaller != 0){
        swap(str[len-1], str[minPos]);
        cout<<str<<endl;
    }
    else{
        swap(str[len-1], str[minPos]);
        cout<<str<<endl;
    }

    return 0;
}
