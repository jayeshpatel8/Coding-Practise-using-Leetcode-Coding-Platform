class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
     vector<int> m(101,-1);
        for (int i=0; i<pieces.size(); i++){
            m[pieces[i][0]]=i;
        }
        for (int i=0; i<arr.size();){
            if (m[arr[i]]==-1) return false;
            for (auto k :  pieces[m[arr[i]]]){
                if (k != arr[i]) return false;
                i++;
            }       
        }
        return true;
    }
};