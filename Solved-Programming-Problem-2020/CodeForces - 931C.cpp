/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: Psychedelic
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n, Max = -INF, Min = INF;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        Min = min(Min, arr[i]);
        Max = max(Max, arr[i]);
    }

    int minEqal = 0;
    if(Max - Min == 2){
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == Min)
                cnta++;
            else if(arr[i] == Max)
                cntc++;
        }
        cntb = (n - (cnta + cntc));

        if(cntb / 2 > min(cnta, cntc)){
            int tempa = cntb / 2, tempb = tempa;
            for(int i = 0; i < n; i++){
                if(arr[i] == Min + 1 && tempa){
                    minEqal++;
                    tempa--;
                    arr[i] -= 1;
                }
                else if(arr[i] == Min + 1 && tempb){
                    minEqal++;
                    tempb--;
                    arr[i] += 1;
                }
            }
        }
        else{
            int tempa = min(cnta, cntc);
            int tempb = tempa;
            //cout<<Min<<" "<<Max<<" "<<tempa<<" "<<tempb<<endl;
            for(int i = 0; i < n; i++){
                if(arr[i] == Min && tempa){
                    minEqal++;
                    tempa--;
                    arr[i] += 1;
                }
                else if(arr[i] == Max && tempb){
                    minEqal++;
                    tempb--;
                    arr[i] -= 1;
                }
            }
        }
    }
    

    cout<<(n - minEqal)<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}
