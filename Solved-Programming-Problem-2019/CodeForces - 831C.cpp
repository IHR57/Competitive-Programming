//Problem ID: CodeForces - 831C (Jury Marks)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 16/05/19
#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

int a[MAX], b[MAX], cs[MAX], vis[MAX];
set<int> s;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>k>>n;

    for(int i = 1; i <= k; i++){
        cin>>a[i];
        cs[i] = a[i] + cs[i-1];
    }
    for(int i = 1; i <= n; i++){
        cin>>b[i];
        s.insert(b[i]);
    }

    set<int> st;
    int temp = 0, res = 0;
    for(int i = 1; i <= k; i++){
        int temp = b[1] - cs[i];
        set<int> tst;
        if(st.find(temp) == st.end()){
            for(int j = 1; j <= k; j++){
                int t = temp + cs[j];
                //cout<<t<<endl;
                if(s.find(t) != s.end()){
                    tst.insert(t);
                }
            }
            if(tst.size() == n)
                res++;
        }
        st.insert(temp);
    }

    cout<<res<<endl;

    return 0;
}
