class Solution {
public:
    string compressedString(string word) {
        string ans;
        int cnt='0', prev=word[0];
        for (auto c :  word){
            if (prev != c || cnt=='9' ){
                ans += cnt;
                ans += prev;
                cnt='0';
            }            
            prev=c;
            cnt++;
        }
        if (cnt != '0'){
                ans += (cnt);
                ans += prev;
        }
            
        return ans;
    }
};
