#include <iostream>
using namespace std;
#define MAX_NODE 6000005
#define MAX_NUM 1000000

bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int node[MAX_NODE][2];
int counter[MAX_NODE];
int nodeNo, root, arrNode[1000005];

struct sNode
{
    int id, val;
    sNode(int pos, int v) {
        id = pos;
        val = v;
    }
    sNode() {};
}sTree1[4000005], sTree2[4000005];


sNode compareMin(sNode a, sNode b)
{
    if(a.val == b.val) {
        if(a.id < b.id)
            return a;
        return b;
    }
    else {
        if(a.val < b.val)
            return a;
        return b;
    }
}

sNode compareMax(sNode a, sNode b)
{
    if(a.val == b.val) {
        if(a.id > b.id)
            return a;
        return b;
    }
    else {
        if(a.val > b.val)
            return a;
        return b;
    }
}
void build(int x, int low, int high, int type)
{
    if(low == high) {
        if(type == 0) {
            sTree1[x].id = low;
            sTree1[x].val = -1;
        }
        else {
            sTree2[x].id = low;
            sTree2[x].id = INT_MAX;
        }
        return;
    }

    int mid = (low + high) >> 1;
    build(x * 2, low, mid, type);
    build(x * 2 + 1, mid + 1, high, type);
    if(type == 0)
        sTree1[x] = compareMax(sTree1[x*2], sTree1[x*2+1]);
    else
        sTree2[x] = compareMin(sTree2[x*2], sTree2[x*2+1]);
}

void init()
{
    root = 0;
    nodeNo = 0;

    build(1, 1, MAX_NUM, 0);
    build(1, 1, MAX_NUM, 1);

    for(int i = 0; i < MAX_NODE; i++)
        counter[i] = 0;

    for(int i = 0; i < 2; i++){
        node[root][i] = -1;
    }
}

int strLen(char* str)
{
    int len = 0;
    while(str[len] != '\0') len++;

    return len;
}

void getBinStr(char* str, int n)
{
    int k = 0;
    for(int i = 31; i >= 0; i--) {
        if(checkBit(n, i)) {
            str[k] = '1';
        }
        else {
            str[k] = '0';
        }
        k++;
    }

    str[k] = '\0';

}


int insertTrie(char* str)
{
    int len = strLen(str), id;
    int curr = root;
    int temp = 0;

    for(int i = 0; i < len; i++){
        id = (str[i] == '0') ? 0 : 1;
        if(node[curr][id] == -1){
            node[curr][id] = ++nodeNo;
            for(int j = 0; j < 2; j++){
                node[nodeNo][j] = -1;
            }
        }

        curr = node[curr][id];
        if(i == 30) {
            temp = curr;
        }
        counter[curr]++;
    }

    return temp;
}

void deleteTrie(char* str)
{
    int len = strLen(str), id;
    int curr = root;

    for(int i = 0; i < len; i++){
        id = (str[i] == '0') ? 0 : 1;
        curr = node[curr][id];
        counter[curr]--;
    }

}

int getMin(int nodeN)
{
    int curr = nodeN;
    int ans = 0;

    for(int i = 0; i < 32; i++){
        if(counter[node[curr][0]] && node[curr][0] != -1){
            curr = node[curr][0];
        }
        else if(counter[node[curr][1]] && node[curr][1] != -1) {
            curr = node[curr][1];
            ans += (1<<(31 - i));
        }
    }

    return ans;
}

int getMax(int nodeN)
{
    int curr = nodeN;
    int ans = 0;

    for(int i = 0; i < 32; i++){
        if(counter[node[curr][1]] && node[curr][1] != -1) {
            curr = node[curr][1];
            ans += (1<<(31 - i));
        }
        else if(counter[node[curr][0]] && node[curr][0] != -1){
            curr = node[curr][0];
        }
    }

    return ans;
}

void update(int x, int l, int r, int pos, int val, int type)
{
    if(pos > r || pos < l)
        return;
    if(l >= pos && r <= pos) {
        if(type == 0) {
            sTree1[x].id = pos;
            sTree1[x].val = val;
        }
        else {
            sTree2[x].id = pos;
            sTree2[x].val = val;
        }
        return;
    }

    int mid = (l + r) >> 1;
    update(x * 2, l, mid, pos, val, type);
    update(x * 2 + 1, mid + 1, r, pos, val, type);
    if(type == 0)
        sTree1[x] = compareMax(sTree1[x*2], sTree1[x*2+1]);
    else
        sTree2[x] = compareMin(sTree2[x*2], sTree2[x*2+1]);
}

sNode query(int x, int l, int r, int i, int j, int type)
{
    if(i > r || j < l) {
        if(type == 0) {
            return sNode{-1, -1};
        }
        else {
            return sNode{INT_MAX, -1};
        }
    }
    if(l >= i && r <= j) {
        if(type == 0) {
            return sTree1[x];
        }
        else {
            return sTree2[x];
        }
    }
    int mid = (l + r) >> 1;
    sNode s1 = query(x * 2, l, mid, i, j, type);
    sNode s2 = query(x * 2 + 1, mid + 1, r, i, j, type);

    if(type == 0) {
        return compareMax(s1, s2);
    }
    else {
        return compareMin(s1, s2);
    }
}

void add(int P, int N)
{
    char str1[70], str2[70];

    getBinStr(str1, P);
    getBinStr(str2, N);

    int len1 = strLen(str1), len2 = strLen(str2);
    int k = len1;

    for(int i = 0; i < len2; i++) {
        str1[k++] = str2[i];
    }
    str1[k] = '\0';

    arrNode[P] = insertTrie(str1);
    int minN = getMin(arrNode[P]);
    int maxN = getMax(arrNode[P]);
    update(1, 1, MAX_NUM, P, (maxN == 0) ? -1 : maxN, 0);
    update(1, 1, MAX_NUM, P, (minN == 0) ? INT_MAX : minN, 1);
}

int use(int P1, int P2)
{
    sNode x = query(1, 1, MAX_NUM, P1, P2, 0);
    if(x.val == -1) {
        return x.val;
    }

    char str1[70], str2[70];
    getBinStr(str1, x.id);
    getBinStr(str2, x.val);

    int len1 = strLen(str1), len2 = strLen(str2);
    int k = len1;

    for(int i = 0; i < len2; i++) {
        str1[k++] = str2[i];
    }
    str1[k] = '\0';

    deleteTrie(str1);

    int minN = getMin(arrNode[x.id]);
    int maxN = getMax(arrNode[x.id]);
    update(1, 1, MAX_NUM, x.id, (maxN == 0) ? -1 : maxN, 0);
    update(1, 1, MAX_NUM, x.id, (minN == 0) ? INT_MAX : minN, 1);
}

int minPower(int P1, int P2)
{
    sNode x = query(1, 1, MAX_NUM, P1, P2, 1);
    if(x.val == INT_MAX)
        return -1;
    return x.val;
}

void shift(int P1, int P2)
{

}

int main()
{
    init();
    int tt;

    cin>>tt;

    while(tt--)
    {
        int N, which_function_need_to_call, P1, P2;
        cin>>which_function_need_to_call;
        if(which_function_need_to_call==1) {
            cin>>P1>>N;
            add(P1, N);
        }
        else if(which_function_need_to_call==2)
        {
            cin>>P1>>P2;
            cout<<use(P1, P2)<<endl;
        }
        else if(which_function_need_to_call==3)
        {
            cin>>P1>>P2;
            cout<<minPower(P1, P2)<<endl;
        }
        else if(which_function_need_to_call==4)
        {
            cin>>P1>>P2;
            shift(P1, P2);
        }
    }
    return 0;
}
