#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> sherlock;
    vector<int> moriatry;

    int digit[10], temp[10];
    char ch;
    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>ch;
        sherlock.push_back(ch-48);      //convert character to integer and store it in vector
    }

    for(int i = 0; i < 10; i++){
        digit[i] = 0;
        temp[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin>>ch;
        moriatry.push_back(ch - 48);
        digit[ch-48]++;     //count the number of digit
        temp[ch-48]++;
    }

    int Min_count = 0, Max_count = 0;

    for(int i = 0; i < n; i++){
        if(digit[sherlock[i]]){
            digit[sherlock[i]]--;
            Min_count++;
        }
        else{
            for(int j = 0; j < 10; j++){
                if(digit[j] && j > sherlock[i]){
                    Min_count++;
                    digit[j]--;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(temp[j] && j > sherlock[i]){
                Max_count++;
                temp[j]--;
                break;
            }
        }
    }

    cout<<n - Min_count<<endl;
    cout<<Max_count<<endl;

    return 0;
}
