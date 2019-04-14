//Problem ID: CodeForces - 1085C (Connect Three)
//Programmer: IQBAL HOSSAIN     Description: MATH/Implementation
//Date: 11/04/19
#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

void print(int ax, int ay, int tempx, int tempy)
{
    if(ax <= tempx){
        for(int i = ax; i < tempx; i++){
            cout<<i<<" "<<ay<<endl;
        }
        if(ay <= tempy){
            for(int i = ay; i < tempy; i++){
                cout<<tempx<<" "<<i<<endl;
            }
        }
        else{
            for(int i = ay; i > tempy; i--){
                cout<<tempx<<" "<<i<<endl;
            }
        }
    }
    else{
        for(int i = ax; i > tempx; i--){
            cout<<i<<" "<<ay<<endl;
        }
        if(ay <= tempy){
            for(int i = ay; i < tempy; i++){
                cout<<tempx<<" "<<i<<endl;
            }
        }
        else{
            for(int i = ay; i > tempy; i--){
                cout<<tempx<<" "<<i<<endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ax, ay, bx, by, cx, cy;
    int tempx, tempy;

    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if(cx > max(ax, bx)){
        tempx = max(ax, bx);
    }
    else if(cx >= min(ax, bx) && cx <= max(ax, bx)){
        tempx = cx;
    }
    else if(cx < min(ax, bx)){
        tempx = min(ax, bx);
    }
    if(cy > max(ay, by)){
        tempy = max(ay, by);
    }
    else if(cy >= min(ay, by) && cy <= max(ay, by)){
        tempy = cy;
    }
    else if(cy < min(ay, by)){
        tempy = min(ay, by);
    }

    int n = abs(ax - tempx) + abs(ay - tempy) + abs(bx - tempx) + abs(by - tempy) + abs(cx - tempx) + abs(cy - tempy) + 1;
    cout<<n<<endl;

    cout<<tempx<<" "<<tempy<<endl;

    print(ax, ay, tempx, tempy);
    print(bx, by, tempx, tempy);
    print(cx, cy, tempx, tempy);

    return 0;
}
