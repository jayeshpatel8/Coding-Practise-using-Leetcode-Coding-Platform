class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
     stack<int> st;
     vector<int> ans(temp.size());
        
        for (int len = temp.size(), i = len-1; i>=0; i--){
            int  j= i + 1;
            while(j <len && temp[j] <= temp[i])
                 j = ans[j] > 0 ? ans[j] + j : len;
            if (j < len)           
                ans[i] = j - i;
        }
        return ans;
    }
};