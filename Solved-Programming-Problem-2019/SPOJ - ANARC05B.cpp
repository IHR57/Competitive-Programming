//Problem ID: SPOJ - ANARC05B (The Double HeLix)
//Programmer: IQBAL HOSSAIN     Description: Binary_Search / Greedy / DP
//Date: 28/03/19
//Problem Link: https://www.spoj.com/problems/ANARC05B/
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

typedef long long ll;

vector<int> a, b, t;

int main()
{
    int n1, n2, val, cs1, cs2;

    while(scanf("%d", &n1) == 1){
        if(!n1) break;
        cs1 = 0, cs2 = 0;
        for(int i = 0; i < n1; i++){
            scanf("%d", &val);
            a.push_back(val);
            cs1 += val;
        }
        scanf("%d", &n2);
        for(int i = 0; i < n2; i++){
            scanf("%d", &val);
            b.push_back(val);
            cs2 += val;
        }

        for(int i = 0; i < a.size(); i++){
            if(binary_search(b.begin(), b.end(), a[i])){
                t.push_back(a[i]);
            }
        }
        if(t.size() == 0){
            printf("%d\n", max(cs1, cs2));
            t.clear(); a.clear(); b.clear();
            continue;
        }
        int sum = 0, k = 0;
        vector<int> t1, t2;
        for(int i = 0; i < a.size(); i++){
            if(k < t.size() && a[i] == t[k]){
                t1.push_back(sum);
                //cout<<sum<<endl;
                k++;
                sum = 0;
            }
            else{
                sum += a[i];
            }
        }
        t1.push_back(sum);

        sum = 0, k = 0;
        int ans = 0;
        for(int i = 0; i < b.size(); i++){
            if(k < t.size() && b[i] == t[k]){
                t2.push_back(sum);
                ans += t[k];
                k++;
                sum = 0;
            }
            else{
                sum += b[i];
            }
        }
        t2.push_back(sum);
//        for(int i = 0; i < t1.size(); i++){
//            cout<<t1[i]<<" ";
//        }
//        cout<<endl;
//        for(int i = 0; i < t2.size(); i++)
//            cout<<t2[i]<<" ";
//        cout<<endl;
        for(int i = 0; i < t1.size(); i++){
            ans += max(t1[i], t2[i]);
        }

        printf("%d\n", ans);
        a.clear();
        b.clear();
        t.clear();
    }

    return 0;
}
