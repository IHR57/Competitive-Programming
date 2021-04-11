class Solution {
public:
    int maxDiff(int num) {
        string sx = "", sy = "";
        int temp = num;
        while(temp){
            sx += ((temp % 10) + 48);
            temp /= 10;
        }
        
        temp = num;
        while(temp){
            sy += ((temp % 10) + 48);
            temp /= 10;
        }
        
        set<char> s1, s2;
        reverse(sx.begin(), sx.end());
        reverse(sy.begin(), sy.end());
        
        int ad = -1, bd = -1;
        for(int i = 0; i < sx.size(); i++){
            if(sx[i] != '9' && ad == -1){
                ad = (sx[i] - 48);
            }
            s1.insert(sx[i]);
        }
        
        for(int i = 0; i < sy.size(); i++){
            if((sy[i] - 48) > 1 && bd == -1){
                bd = (sy[i] - 48);
            }
            s2.insert(sy[i]);
        }
        
        int a = num;
        if((s1.size() > 1 && ad != -1) || (s1.size() == 1 && ad != 9)){
            temp = num, a = 0;
            int x = 1;
            while(temp){
                int t = temp % 10;
                if(t == ad)
                    a += 9 * x;
                else
                    a += t * x;
                x *= 10;
                temp /= 10;
            }
        }
        //cout<<a<<endl;
       // cout<<bd<<endl;
        int b = num;
        if((s2.size() > 1 && bd != -1) || (s2.size() == 1 && bd != -1)){
            temp = num, b = 0;
            int x = 1;
            int tx = 0;
            if(s2.size() == 1 || (s2.size() > 1 && (sy[0]-48) == bd))
                tx = 1;
            while(temp){
                int t = temp % 10;
                if(t != bd){
                    b += t * x;
                }else{
                    b += tx * x;
                }
                x *= 10;
                temp /= 10;
            }
        }
        //cout<<b<<endl;
        return a - b;
    }
};