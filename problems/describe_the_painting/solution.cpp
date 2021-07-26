class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long start[100001]={};
        bool end[100001]={};
        int minIdx=INT_MAX, maxIdx=0;
        for ( auto &s : segments){
            start[s[0]] += s[2];
            start[s[1]] -= s[2];
            end[s[1]]=true;
            minIdx  = min({minIdx, s[0], s[1]});
            maxIdx  = max({maxIdx, s[0], s[1]});
        }
        vector<vector<long long>> ans;
        long long col=start[minIdx]; 
        int prev = minIdx;
        for (int i =minIdx+1; i<=maxIdx; i++){
            if (start[i] || end[i]){
                if (col)
                    ans.push_back({prev,i,col});                
                col +=start[i];
                prev=i;
            }
        }
        return ans;
    }
};