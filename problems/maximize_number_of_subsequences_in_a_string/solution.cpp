class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long ans=0;
        int a=0,b=0;
        if (pattern[0]  == pattern[1]){
            for (auto &i : text){
                if (i == pattern[0]) 
                    a++;
            }
            return  (long long)a * (a+1) / 2;
        }
        for (auto &i : text){
            if (i == pattern[0]) a++;
            else if (i == pattern[1]) {
                ans += a;
                b++;
            }
        }
        return ans  + max(a,b);
    }
};