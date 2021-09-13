class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[128]={};
        for (auto c : text) freq[c]++;
        int ans=0;
         ans = freq['b'];
         ans = min(ans, freq['a']);
         ans = min(ans, freq['l']/2);
         ans = min(ans, freq['o']/2);
         ans = min(ans, freq['n']);
        return ans;
    }
};