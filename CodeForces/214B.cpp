#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int mark[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, Zero = 0, sum = 0, value;
    vector<int> v;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>value;
        v.push_back(value);
        if(value == 0)
            Zero = 1;
        sum += value;
    }

    if(!Zero){
        cout<<-1<<endl;
    }
    else{
        sort(v.begin(), v.end());
        if(sum == 0){
            cout<<0<<endl;
            return 0;
        }
        else if(sum % 3 == 0){
            reverse(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++){
                cout<<v[i];
            }
            cout<<endl;
        }
        else if(sum % 3 == 1){
            int t = 0;
            bool flag = false;
            for(int i = 0; i < v.size(); i++){
                if(v[i] % 3 == 1){
                    flag = true;
                    mark[i] = 1;
                    break;
                }
            }
            if(flag){
                vector<int> temp;
                for(int i = 0; i < v.size(); i++){
                    if(!mark[i]){
                        temp.push_back(v[i]);
                        t += v[i];
                    }
                }

                if(t == 0){
                    cout<<0<<endl;
                    return 0;
                }
                reverse(temp.begin(), temp.end());
                for(int i = 0; i < temp.size(); i++){
                    cout<<temp[i];
                }
                cout<<endl;
            }
            if(!flag){
                int cnt = 0;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] % 3 == 2){
                        cnt++;
                        flag = true;
                        mark[i] = 1;
                        if(cnt == 2)
                            break;
                    }
                }
                if(flag){
                    vector<int> temp;
                    for(int i = 0; i < v.size(); i++){
                        if(!mark[i]){
                            temp.push_back(v[i]);
                            t += v[i];
                        }
                    }

                    if(t == 0){
                        cout<<0<<endl;
                        return 0;
                    }
                    reverse(temp.begin(), temp.end());

                    for(int i = 0; i < temp.size(); i++)
                        cout<<temp[i];
                    cout<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
        else if(sum % 3 == 2){
            int t = 0;
            bool flag = false;
            for(int i = 0; i < v.size(); i++){
                if(v[i] % 3 == 2){
                    flag = true;
                    mark[i] = 1;
                    break;
                }
            }
            if(flag){
                vector<int> temp;
                for(int i = 0; i < v.size(); i++){
                    if(!mark[i]){
                        temp.push_back(v[i]);
                        t += v[i];
                    }
                }

                if(t == 0){
                    cout<<0<<endl;
                    return 0;
                }
                reverse(temp.begin(), temp.end());
                for(int i = 0; i < temp.size(); i++){
                    cout<<temp[i];
                }
                cout<<endl;
            }
            if(!flag){
                int cnt = 0;
                for(int i = 0; i < v.size(); i++){
                    if(v[i] % 3 == 1){
                        cnt++;
                        flag = true;
                        mark[i] = 1;
                        if(cnt == 2)
                            break;
                    }
                }
                if(flag){
                    vector<int> temp;
                    for(int i = 0; i < v.size(); i++){
                        if(!mark[i]){
                            temp.push_back(v[i]);
                            t += v[i];
                        }
                    }

                    if(t == 0){
                        cout<<0<<endl;
                        return 0;
                    }
                    reverse(temp.begin(), temp.end());

                    for(int i = 0; i < temp.size(); i++)
                        cout<<temp[i];
                    cout<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
    }

    return 0;
}
