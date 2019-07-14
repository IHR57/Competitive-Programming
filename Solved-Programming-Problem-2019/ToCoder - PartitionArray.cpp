#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

class PartitionArray
{
    public:
        vector <int> positiveSum(vector <int> a)
        {
            int sum = 0;
            vector<int> res;
            for(int i = 0; i < a.size(); i++){
                sum += a[i];
            }
            if(sum > 0){
                vector<int> res;
                res.push_back(a.size());
                return res;
             }
            else
                return {-1};
        }

};