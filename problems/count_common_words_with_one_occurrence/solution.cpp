class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> w1;
        
        for (auto s : words1) w1[s]++;
        for (auto s : words2) 
            if (w1.count(s) && w1[s] <=1 )
                w1[s]--;
        int ans =0;
        for (auto & [k,v] : w1) 
             ans+=v==0;
        return ans;
    }
};