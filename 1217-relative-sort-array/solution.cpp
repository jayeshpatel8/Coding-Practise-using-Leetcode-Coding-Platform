class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int f[1001]={};
        for (auto i : arr1) f[i]++;
        for (auto i : arr2){
            for (int j=0; j<f[i]; j++)
                ans.push_back(i);
            f[i]=0;
        }
        for (int i=0; i<1001; i++){
            for (int j=0; j<f[i]; j++)
                ans.push_back(i);
        }
        return ans;
    }
};
