class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        for (auto &s : words) map[s]++;
        int ans = 0,same = 0, pal = 0;
        for (auto &[k,v] : map){
            if (k[0] == k[1]){
                if (v > 1){
                    ans  += v & 0xFFFFFFFE;
                    v &= 1;
                }
                if (v) same=1;
            }
            else{
                string r = k;
                reverse(begin(r),end(r));
                auto it = map.find(r);
                if (it == map.end()) continue;
                int mini = min(v,it->second);
                pal += mini;
                v -= mini;
                it->second -= mini;
            }
        }

        return ans * 2 + pal * 4  + (same ? 2  : 0 );
    }
};