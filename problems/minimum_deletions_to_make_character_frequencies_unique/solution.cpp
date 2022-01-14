class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (auto i : s) freq[i-'a']++;
        
        sort(rbegin(freq),rend(freq));
        int ans = 0;
        int prev=INT_MAX;
        for (auto i : freq){
            if (i < prev) prev = i;
            else{
                prev = max(prev-1,0);
                ans += i  - prev;
            }

        }

        return ans;
    }
};