//Problem ID: CodeForces - 1080C (Masha and Two Friends)
//Programmer: IQBAL HOSSIAN     Description: Implementation/MATH
//Date: 13/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
ll black, white;

ll checkStart(ll x, ll y)
{
    if(x % 2 == 0){
        if(y % 2 == 0)
            return 0;
        else
            return 1;
    }
    else{
        if(y % 2 == 0)
            return 1;
        else
            return 0;
    }
}

void compute(ll x1, ll y1, ll x2, ll y2, ll idx)
{
    ll t = checkStart(x1, y1);
    ll area = 1LL * (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
    ll tw = area / 2, tb = area / 2;
    if(area % 2 == 1){
       if(t == 0)   tw++;
       else tb++;
    }
    white -= tw, black -= tb;
    if(idx == 0)
        white  += area;
    else
        black += area;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n, m, x1, y1, x2, y2, x3, y3, x4, y4;

    cin>>t;

    while(t--){
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        ll area = (1LL * n * m);

        white = (area / 2), black = (area / 2);
        if(area % 2 == 1)
            white++;

        ll tx1, tx2, ty1, ty2;
        tx1 = max(x1, x3), ty1 = max(y1, y3);
        tx2 = min(x2, x4), ty2 = min(y2, y4);

        if(tx1 <= tx2 && ty1 <= ty2){       //overlapped
            compute(x3, y3, x4, y4, 1);
            area = 1LL * (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
            ll tx = checkStart(x1, y1);
            ll tw = area / 2, tb = area / 2;
            if(area % 2){
                if(tx == 0)  tw++;
                else    tb++;
            }
            area = 1LL * (abs(tx1 - tx2) + 1) * (abs(ty1 - ty2) + 1);
            tx = checkStart(tx1, ty1);
            ll ttw = area / 2, ttb = area / 2;
            if(area % 2){
                if(tx == 0)  ttw++;
                else ttb++;
            }
            tw -= ttw, tb -= ttb;
            white += tb;
            if(tb > 0) black -= tb;
            //white -= area;
        }
        else{
            compute(x1, y1, x2, y2, 0);
            compute(x3, y3, x4, y4, 1);
        }

        cout<<white<<" "<<black<<endl;
    }

    return 0;
}
