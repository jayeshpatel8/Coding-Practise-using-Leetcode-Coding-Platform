unordered_map<int, bool> dp;
bool canCross_(vector<int>& s, int pos, int k){
    int n=s.size();
    if (pos >=n-1) return true;
    int key = pos|k<<11;
    if (dp.count(key)) return dp[key];
    for (int i=pos+1; i<n; i++)
    {
        int diff = s[i]-s[pos];
        if (diff < k-1) continue;
        if (diff > k+1) return dp[key]=false;
        if (canCross_(s,i,diff)) return dp[key]=true;
    }
    return dp[key]=false;
}
class Solution {
public:
    bool canCross(vector<int>& s) {
        dp.clear();
        return canCross_(s,0,0); 
    }
};