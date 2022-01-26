class Solution {
public:
    int rank[26][26]={};
    string rankTeams(vector<string>& votes) {
        int  N= votes.size() , L = votes[0].size();
        if (N==1) return votes[0];

        for (int  i=0; i<L; i++)
            for (auto &s :votes)
                rank[i][s[i] - 'A']++;
        
        sort(begin(votes[0]),end(votes[0]),[&](char a, char b)
             {
                 for (int i=0; i<26; i++){
                     if (rank[i][a-'A']  == rank[i][b-'A']) continue;
                     return rank[i][a-'A']  > rank[i][b-'A'];
                 }
                 return a <  b;                 
             });
        return votes[0];
    }
};