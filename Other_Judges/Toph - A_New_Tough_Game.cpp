//Contest: IUT 10th ICT FEST 2019 Problem: E
#include <bits/stdc++.h>
#define MAX 2005
using namespace std;

//int fun(string str)
//{
//    string t = "pinkfloyd";
//    int response = 0;
//    int len = str.length();
//
//    for(int i = 0; i < len; i++){
//        response += abs(str[i] - t[i]);
//    }
//    return response;
//}

int main()
{
    int n, prev, curr;
    string str;

    cin>>n;
    for(int i = 0; i < n; i++)
        str += "a";
    cout<<"? "<<str<<endl;
    cin>>prev;

    for(int i = 0; i < n; i++){
        str[i] = 'z';
        cout<<"? "<<str<<endl;
        cin>>curr;
        if(prev >= curr){
            int temp = 25 - ((25 - (prev - curr)) / 2);
            str[i] = 97 + temp;
            //cout<<str<<endl;
            prev = curr - (25 - temp);
        }
        else{
            int temp = (25 - (curr - prev)) / 2;
            str[i] = 97 + temp;
            //cout<<str<<endl;
            prev = (curr - (25 - temp));
        }
    }
    cout<<"! "<<str<<endl;

    return 0;
}
