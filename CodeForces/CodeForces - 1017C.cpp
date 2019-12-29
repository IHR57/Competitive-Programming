//Problem ID: CodeForces - 1017C (The Phone Number)
//Programmer: IQBAL HOSSAIN     Description: MATH/Greedy
//Date: 22/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, idx = 2;

    cin>>n;
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }

    int Min = 2147483647, temp;

    for(int i = 1; i *i <= n; i++){
        temp = i;
        int rem = n / i;
        if(n % i)
            rem++;
        if(temp + rem < Min){
            Min = temp + rem;
            idx = temp;
        }
    }

    int k = 1;
    for(int i = 0; i < idx * (n / idx); i++){
        if(i % idx == 0){
            temp = k * idx;
            k++;
            cout<<temp<<" ";
        }
        else{
            temp--;
            cout<<temp<<" ";
        }
    }

    int rem = n - (idx * (n / idx));
    temp = n;
    for(int i = 1; i <= rem; i++){
        cout<<temp<<" ";
        temp--;
    }
    cout<<endl;

    return 0;
}
