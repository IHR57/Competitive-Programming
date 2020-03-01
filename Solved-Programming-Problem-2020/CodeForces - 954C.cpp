//Date: 15/02/2020
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
#define MAX 200005
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
 
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
    
    int n;

    cin>>n;

    int minVal = INF, maxVal = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }    

    if(n == 1){
        cout<<"YES"<<endl;
        cout<<1<<" "<<arr[0]<<endl;
        return 0;
    }

    int col = -1;
    bool foundCol = false;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            cout<<"NO"<<endl;
            return 0;
        }
        if(abs(arr[i] - arr[i-1]) > 1){
            foundCol = true;
            int temp = abs(arr[i] - arr[i-1]);
            if(col == -1)
                col = temp;
            else{
                if(temp != col){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }

    if(!foundCol)
        col = 1;

    int Mx = maxVal;
    if(maxVal % col != 0)
        Mx = (maxVal) + (col - (maxVal % col));
    int row = Mx / col;

    if(col != 1){
        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) == 1){
                int val1 = (arr[i] % col == 0) ? arr[i]/col - 1 : arr[i]/col;
                int val2 = (arr[i-1] % col == 0) ? (arr[i-1])/col - 1 : arr[i-1]/col;
                if(val1 != val2){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"YES"<<endl;
    cout<<row<<" "<<col<<endl;

    return 0;
}