class Solution {
public:
    bool halvesAreAlike(string s) {
        string vo="aeiouAEIOU";
        int cnt=0;
        int n = s.size();
        for (auto i=0; i<n/2; i++){
            auto c  = s[i];
            if (vo.find(c) != string::npos){
                cnt++;
            }
        }
        for (auto i=n/2; i<n; i++){
            auto c  = s[i];
            if (vo.find(c) != string::npos){
                cnt--;
            }
        }
        
        return (cnt) == 0;
    }
};
