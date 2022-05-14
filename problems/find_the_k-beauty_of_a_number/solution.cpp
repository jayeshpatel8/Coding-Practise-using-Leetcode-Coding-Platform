class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        for (int i=0; i<s.size(); i++){
            int n = 0,cnt=0;
            for (int j=i; cnt<k && j<s.size(); j++,cnt++){
                n = n*10 + s[j]-'0';
            }
            if (cnt ==k && n){
             
                ans += (num%n) == 0;
            }
        }
        return ans;
    }
};