class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> ans;
        int mans=INT_MAX;
        for(int i=1; i<arr.size(); i++)
            if ((arr[i]- arr[i-1]) < mans)
                mans = (arr[i] - arr[i-1]);
        for(int i=1; i<arr.size(); i++){
            if (arr[i]- arr[i-1] == mans)
                ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
    }
};