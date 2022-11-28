class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> result(100001,-1);
        for (auto i : matches){
            auto win = i[0], los = i[1];
            if (result[win] == -1) result[win]=0;
            if (result[los] == -1) result[los]=1;
            else result[los]++;
        }
        vector<vector<int>> ans(2);
        for (int i=1; i<=100000; i++){
            if (result[i]==0) ans[0].push_back(i);
            else if (result[i]==1) ans[1].push_back(i);
        }
        return ans;
    }
    vector<vector<int>> findWinners2(vector<vector<int>>& matches) {
        unordered_map<int,int> loser;
        for (auto i : matches) loser[i[1]]++;
        vector<vector<int>> ans;
        set<int> winner, singlerloser;
        for (auto i : matches)  
            if (loser.count(i[0])==0) winner.insert(i[0]);
        for  ( auto &[k,v] : loser)
            if (v==1) singlerloser.insert(k);
        ans.push_back(vector<int>(begin(winner),end(winner)));
        ans.push_back(vector<int>(begin(singlerloser),end(singlerloser)));
        return ans;
    }
};