bool comp(vector<int>& a, vector<int>& b){
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n)
        {
            sort(intervals.begin(),intervals.end(),comp);
            res.push_back(vector<int>({intervals[0][0],intervals[0][1]}));
        }
        int j=0;    
        for (int i=0; i<n;i++)
        {
            if (res[j][1]<intervals[i][0]){
                res.push_back(vector<int>({intervals[i][0],intervals[i][1]}));
                j++;
            }
            else
            {
                if (res[j][1]<intervals[i][1])
                res[j][1]=intervals[i][1];
            }
        }
        return res;
    }
};