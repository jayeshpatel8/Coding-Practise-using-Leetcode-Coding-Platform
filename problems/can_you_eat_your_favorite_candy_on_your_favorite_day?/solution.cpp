class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        uint64_t prefix[100000];
        
        prefix[0] = candiesCount[0];
        for (int i=1; i< candiesCount.size(); i++)
            prefix[i] = prefix[i-1]+candiesCount[i];
        int m =queries.size();
        vector<bool> res(m,false);
        for (int i=0; i<m;i++ ){
            int type = queries[i][0];
            int day = queries[i][1];
            int cap = queries[i][2];
            
            res[i] = !(prefix[type]<=day || (prefix[type]-candiesCount[type])/cap>day);
        }
        return res;
    }
};