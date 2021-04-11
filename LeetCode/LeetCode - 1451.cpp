class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int, int> >vp;
        vector<string> vs;
        text += " ";
        
        int n = text.size();
        
        string temp = "";
        int k = 0;
        for(int i = 0; i < n; i++){
            if(text[i] != ' ')
                temp += text[i];
            else{
                vs.push_back(temp);
                vp.push_back(make_pair(temp.size(), k));
                k++;
                temp = "";
            }
        }
        
        sort(vp.begin(), vp.end());
        
        string res = "";
        for(int i = 0; i < vp.size(); i++){
            res += vs[vp[i].second];
            if(i != vp.size() - 1)
                res += " ";
        }
        
        if(res[0] >= 'a' && res[0] <= 'z'){
            int idx = res[0] - 32;
            res[0] = idx;
        }
        
        for(int i = 1; i < res.size(); i++){
            if(res[i] >= 'A' && res[i] <= 'Z')
                res[i] = (res[i] + 32);
        }
        
        return res;
        
    }
};