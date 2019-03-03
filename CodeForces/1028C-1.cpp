#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

struct data
{
    int x1, y1, x2, y2;
};

vector<data> tree;
vector<data> arr;

data combine(data d1, data d2)
{
    data ans;
    ans.x1 = max(d1.x1, d2.x1);
    ans.y1 = max(d1.y1, d2.y1);
    ans.x2 = min(d1.x2, d2.x2);
    ans.y2 = min(d1.y2, d2.y2);

    return ans;
}

void build(int nodeNo, int low, int high)
{
    //cout<<"I am here"<<endl;
    if(low == high){
        tree[nodeNo] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(nodeNo * 2, low, mid);
    build(nodeNo * 2 + 1, mid + 1, high);

    tree[nodeNo] = combine(tree[nodeNo *  2] , tree[nodeNo * 2 + 1]);
}

data query(int nodeNo, int low, int high, int i, int j)
{
    //cout<<"I am here"<<endl;
    if(low == i && high == j)
        return tree[nodeNo];
    int mid = low + (high - low) / 2;
    if(j <= mid){
        return query(nodeNo * 2, low, mid, i, j);
    }
    else if(mid < i){
        return query(nodeNo * 2 + 1, mid + 1, high, i, j);
    }
    else{
        data l = query(nodeNo * 2, low, mid, i, mid);
        data r = query(nodeNo * 2 + 1, mid + 1, high, mid + 1, j);
        return combine(l, r);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;

    cin>>n;
    arr = vector<data> (n + 1);
    tree = vector<data> (5 * n + 1);

    for(int i = 1; i <= n; i++){
        cin>>arr[i].x1>>arr[i].y1>>arr[i].x2>>arr[i].y2;
    }

    build(1, 1, n);

    data temp = query(1, 1, n, 2, n);
    if(temp.x1 <= temp.x2 && temp.y1 <= temp.y2){
        cout<<temp.x1<<" "<<temp.y1<<endl;
        return 0;
    }

    temp = query(1, 1, n, 1, n - 1);
    if(temp.x1 <= temp.x2 && temp.y1 <= temp.y2){
        cout<<temp.x1<<" "<<temp.y1<<endl;
        return 0;
    }

    for(int i = 2; i < n; i++){
        data temp1 = query(1, 1, n, 1, i - 1);
        data temp2 = query(1, 1, n, i + 1, n);
        temp = combine(temp1, temp2);
        if(temp.x1 <= temp.x2 && temp.y1 <= temp.y2){
            cout<<temp.x1<<" "<<temp.y2<<endl;
            return 0;
        }
    }

    return 0;
}
