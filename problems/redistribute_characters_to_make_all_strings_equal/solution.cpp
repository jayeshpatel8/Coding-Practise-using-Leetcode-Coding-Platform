class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = 0;
        int ch[128]={};
        for (auto s : words){
            for (auto c : s) ch[c]++;
            n++;
        }
        //if (n == 1) return true;
        for (int i = 'a'; i<='z'; i++){
            if (ch[i] % n) return false;
        }
        return true;
    }
};