class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(128);
        for (auto  c : s1) freq1[c]++;
        int ans=0, cnt = s1.length();
        for (int i=0,N=cnt-1; i<s2.length(); i++){
            if (freq1[s2[i]]-- >=1) cnt--;
            if (i>=N){
                ans += cnt==0;
                if (++freq1[s2[i-N]] >0) cnt++;
            }
        }
        return ans;
    }
};