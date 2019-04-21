//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;
int res[MAX], visited[MAX], pos[MAX];

struct data
{
    int pos, l, r, val;
};
data arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, value, idx = 1, tempr, templ;

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        cin>>value;
        data temp;
        if(i == 1){
            temp.l = -1;
            temp.r = i + 1;
        }
        else if(i == n){
            temp.r = -1;
            temp.l = i - 1;
        }
        else{
            temp.l = i - 1;
            temp.r = i + 1;
        }
        temp.val = value, temp.pos = i;
        arr[i] = temp;
        pos[value] = i;
    }

    for(int i = n; i >= 1; i--){
        if(!visited[pos[i]]){
            int ps = pos[i];
            res[ps]  = idx;
            visited[ps] = 1;
            int j = ps, cnt = 0;
//            cout<<"---"<<arr[j].l<<" "<<arr[j].r<<" "<<arr[j].val<<" "<<arr[j].pos<<endl;
            while(true){
                if(arr[j].r != -1 && !visited[arr[j].r]){
                    //arr[j].l = arr[j].r = -1;
                    j = arr[j].r;
                    visited[j] = 1;
                    if(!res[j])
                        res[j] = idx;
                    cnt++;
                    if(cnt == k){
                        tempr = j;
                        break;
                    }
                }
                else{
                    tempr = j;
                    break;
                }
            }
            j = ps, cnt = 0;
            while(true){
                if(arr[j].l != -1 && !visited[arr[j].l]){
                    j = arr[j].l;
                    visited[j] = 1;
                    if(!res[j])
                        res[j] = idx;
                    cnt++;
                    if(cnt == k){
                        templ = j;
                        break;
                    }
                }
                else{
                    templ = j;
                    break;
                }
            }
            //cout<<templ<<" "<<tempr<<endl;
            if(arr[templ].l != -1 && arr[tempr].r != -1){
                int k1 = arr[templ].l, k2 = arr[tempr].r;
                arr[k1].r = k2;
                arr[k2].l = k1;
            }
            idx++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(res[i] % 2){
            cout<<"1";
        }
        else{
            cout<<"2";
        }
    }
    cout<<endl;

    return 0;
}

