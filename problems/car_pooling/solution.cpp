class Solution {
public:
    int freq[1001]={};
    bool carPooling(vector<vector<int>>& trips, int cap) {
        sort(begin(trips), end(trips), [](auto & a, auto &b){ return a[1] == b[1] ? a[2] <b[2] : a[1] < b[1];});
        int m=0;
        for (auto &t : trips)
            freq[t[1]] +=t[0] ,freq[t[2]] -=t[0], m = max(m,t[2]);
        
        for (int i=0, sum=0; i<=m; i++)
        {
            sum += freq[i];
            if (sum > cap) return false;
        }
        return true;
    }
};
