
vector<int> v;
 void combinationSum_util(vector<int>& candidates, int target,int idx,vector<vector<int>> & out) {
     if (target == 0)
          out.push_back(v);
        
     int len=candidates.size();
     for(int i=idx;i<len;i++)
     {
         if  ((target-candidates[i]) <0)
             continue;
         
         v.push_back(candidates[i]);
         combinationSum_util(candidates,target-candidates[i],i,out) ;
         v.pop_back();
     }
 }
     
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        int len=candidates.size();
        
        for(int i=0;i<len;i++)
        {
             if  ((target-candidates[i]) <0)
                 continue;            
            v.push_back(candidates[i]);
            combinationSum_util(candidates, target-candidates[i],i, out);
            v.pop_back();
        }
        return out;
    }
};