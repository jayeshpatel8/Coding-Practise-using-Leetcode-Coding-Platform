void dfs(vector<int>& num,vector<bool>& used,vector<int>& v,vector<vector<int>> & r)
{
    if (v.size() == num.size()) {
        r.push_back(v); 
        return;
    }
    for (int i =0; i<num.size();i++){
        if(used[i]) continue;
        if (i>0 && num[i]==num[i-1] && !used[i-1] ) continue;
        used[i]=true;
        v.push_back(num[i]);
        dfs(num,used,v,r);
        v.pop_back();
        used[i]=false;
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> r;
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        vector<int> v;
        dfs(nums,used,v,r);
        
        return r;
    }
};