// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

int arr[MAX], tree[MAX*4], visited[MAX], idx[MAX];
const int inf = 1<<28;

void init(int node, int b, int e)
{
    if(b == e){             //base case
        tree[node] = arr[b];
        return;
    }

    //divide and conquer strategy
    int left = node * 2;        //left child of node;
    int right = node * 2 + 1;   //right child of node;
    int mid = (b + e) / 2;

    init(left, b, mid);     //recursive call for left child
    init(right, mid+1, e);      //recursive call for right child

    tree[node] = min(tree[left], tree[right]);      //sub of its two child
}

int query(int node, int b, int e, int i, int j)     //answer for given query
{
    if(i > e || j < b)      //check if we go outside from the given range
        return inf;
    if(b >= i && e <= j)        //if we are in given range
        return tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return min(p1, p2);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, zero = 0, qq = 0;

    cin>>n>>q;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] == 0)
            zero++;
        if(arr[i] == q)
            qq++;
    }

    if(qq == 0){
        if(zero == 0){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            for(int i = 0; i < n; i++){
                if(arr[i] == 0){
                    arr[i] = q;
                    zero--;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            if(i == 0) arr[i] = 1;
            else
                arr[i] = arr[i-1];
        }
    }

    vector<pair<int, int> > sequence(q + 1, {-1, -1});
    for(int i = 0; i < n; i++){
        if(sequence[arr[i]].first == -1){
            sequence[arr[i]].first = sequence[arr[i]].second = i;
        }
        else{
            sequence[arr[i]].second = i;
        }
    }

    init(1, 0, n - 1);

    for(int i = 1; i <= q; i++){
        if(sequence[i].first == -1)
            continue;
        if(query(1, 0, n - 1, sequence[i].first, sequence[i].second) < i){
            cout<<"NO"<<endl;
            return 0;
        }
    }


    cout<<"YES"<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
