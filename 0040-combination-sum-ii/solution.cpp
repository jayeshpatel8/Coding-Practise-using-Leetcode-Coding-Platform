void combinationSum2_util(vector<int>& candidates, vector<vector<int>>& o ,vector<int>& v,int target ,int idx){
    if (0==target) {
        o.push_back(v);
        return ;
    }

     int len = candidates.size();
    for (int i=idx; (i < len); i++)
    {
        if((target - candidates[i]) < 0 ) return ;
        if(i&&candidates[i]==candidates[i-1]&&i>idx) continue;
        
        v.push_back(candidates[i]);
        combinationSum2_util(candidates, o,v,target - candidates[i], i+1);
        v.pop_back();
        
    }    
    return ;
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> o;
        vector<int> v;
        int len = candidates.size();
        
        sort(candidates.begin(), candidates.end());
        combinationSum2_util(candidates, o,v,target, 0);       
        return o;
    }
};
