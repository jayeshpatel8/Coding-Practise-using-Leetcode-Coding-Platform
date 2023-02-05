class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(128,0), ans;
        for (auto c : p) freq[c]++;
        for (int i=0,cnt=p.size(), N = cnt-1; i<s.size(); i++){
            if (freq[s[i]]-- >0) cnt--;
            if (i >= N){
                if (cnt == 0)
                    ans.push_back(i-N);
                if (++freq[s[i-N]]>0)cnt++;
            }
        }
        return ans;
    }
};