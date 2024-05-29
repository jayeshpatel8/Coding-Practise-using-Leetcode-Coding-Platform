class Solution {
public:
    int numSteps(string s) {
        int c =0;
        int N= s.size();
        int ans = 0;
        for (int j = N-1; j>0; j--){
            ans++;
            if (s[j] -'0' + c == 1){
                c=1;
                ans++;
            }
        }
        return ans+c;
    }
};
