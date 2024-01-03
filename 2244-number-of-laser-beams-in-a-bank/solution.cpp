class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> cnt;
        for (auto &s : bank){
            int one = 0;
            for (auto c : s) one  += c == '1';
            cnt.push_back(one);
        }
        int ans = 0;
        for (int prev = 0, i=1; i<n; i++){
            if (cnt[i]){
                //if ( prev+1 != i) 
                    ans += cnt[prev] * cnt[i];
                
                prev=i;
            }
        }
        return ans;
    }
};
