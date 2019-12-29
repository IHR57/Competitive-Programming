//Problem ID: CodeForces - 978D (Almost Arithmetic Progression)
//Programmer: IQBAL HOSSIAN     Description: Brute Force
//Date: 24/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

const int inf = 1<<28;

int dx[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};

int solve(vector<int> v)
{
    int temp = (v[1] - v[0]), cnt = 0;
    for(int i = 2; i < v.size(); i++){
        if((v[i] - v[i-1]) != temp){
            int temp1 = v[i] + 1;
            int temp2 = v[i] - 1;
            if((temp1 - v[i-1]) == temp){
                v[i] = temp1;
                cnt++;
            }
            else if((temp2 - v[i-1]) == temp){
                v[i] = temp2;
                cnt++;
            }
            else
            {
                return inf;
            }
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, val;
    vector<int> arr, temp;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>val;
        arr.push_back(val);
    }

    if(n <= 2){
        cout<<0<<endl;
        return 0;
    }

    int Min = inf;
    for(int i = 0; i < 9; i++){
        temp = arr;
        temp[0] += dx[i];
        temp[1] += dy[i];
        int ans = solve(temp);
        if(dx[i] != 0)
            ans++;
        if(dy[i] != 0)
            ans++;
        Min = min(Min, ans);
        temp.clear();
    }

    (Min >= inf) ? cout<<-1<<endl : cout<<Min<<endl;

    return 0;
}
