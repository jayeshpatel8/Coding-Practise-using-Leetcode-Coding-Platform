class Solution {
public:
    int maxScore(string s) {
        int ones=0,zeros=0,ans=0;
        for (auto c : s)
            ones+= c=='1';
        
        for (auto i=0; i<s.size()-1; i++){
            auto c = s[i];
            if (c=='0')zeros++;
            else ones--;
            ans = max(ans,ones+zeros);
        }
        return ans;
    }
};
