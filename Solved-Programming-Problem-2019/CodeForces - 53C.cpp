//Problem ID: CodeForces - 53C (Little Frog)
//Programmer: IQBAL HOSSAIN     Description: Constructive Algorithms
//Date: 10/01/19
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int main()
{
    int n;

    cin>>n;
    int leftIdx = 1, rightIdx = n;

    while(true){
        if(leftIdx >  rightIdx){
            break;
        }
        if(leftIdx == rightIdx){
            cout<<leftIdx<<" ";
        }
        else
            cout<<leftIdx<<" "<<rightIdx<<" ";
        leftIdx++, rightIdx--;
    }

    cout<<endl;

    return 0;
}
