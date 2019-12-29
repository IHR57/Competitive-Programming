class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string, string> ms;
    map<string, string> msd;
    
    string encode(string longUrl) {
        string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int i = 0, j = 0, k = 0, l = 0;
        string st = "";
        st = str[i] + str[j] + str[k] + str[l];
        l++;
        if(l == 26){
            l = 0;
            k++;
        }
        if(k == 26){
            k = 0;
            j++;
        }
        if(j == 26){
            i++;
            j = 0;
        }
        ms[longUrl] = st;
        msd[st] = longUrl;
        return st;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return msd[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));