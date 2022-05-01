class Solution {
public:
    int maxRepeating(string seq, string word) {
        int ans = 0;
        auto t = word;
        while (seq.find(t) !=seq.npos){
            ans++; t+=word;
        }
        return ans;
    }
};