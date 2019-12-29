//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

//vector<int> div[105];
//
//void divisor(int n)
//{
//    for(int i = 1; i * i <= n; i++){
//        if(n % i == 0){
//            div[n].push_back(i);
//            if((n / i) != i){
//                div[n].push_back(n/i);
//            }
//        }
//    }
//}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, arr[MAX], sum = 0, Min = 1<<28;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    Min = sum;
    sort(arr, arr + n);

    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= 100; j++){
            int temp = sum;
            if(arr[i] % j == 0){
                temp -= (arr[i] - (arr[i] / j));
                temp += ((arr[0] * j) - arr[0]);
                //cout<<temp<<endl;
                Min = min(Min, temp);
            }
        }
    }

    cout<<Min<<endl;

    return 0;
}
