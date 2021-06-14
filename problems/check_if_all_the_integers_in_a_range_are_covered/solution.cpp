class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>  seen(51,0);
        for (auto r : ranges){
            for (int i=r[0]; i<=r[1]; i++)
                seen[i]=1;
        }
        for (int i=left; i<=right; i++){
            if (!seen[i]) return false;            
        }
        return true;
    }
};