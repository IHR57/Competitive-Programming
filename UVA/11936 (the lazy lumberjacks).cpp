#include <iostream>
using namespace std;

int main()
{
    int N, a, b, c;

    cin>>N; //test case

    while(N--){
        cin>>a>>b>>c;
        if((a+b)>c && (b+c)>a && (c+a)>b)   //condition for forming a triangle
            cout<<"OK"<<endl;
        else
            cout<<"Wrong!!"<<endl;
    }

    return 0;
}
