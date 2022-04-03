class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> loss(100001) , win(100001);
        for (auto &i : matches){
            loss[i[1]]++;
            win[i[0]]++;
        }
        vector<int> noloss, oneloss;
        for ( int i=1; i<100001; i++ ){
            if (win[i]){
                if (loss[i] == 0){
                    noloss.push_back(i);
                }
                else if (loss[i] == 1)
                    oneloss.push_back(i);
            }
            else if (loss[i] == 1)
                    oneloss.push_back(i);
        }
        return {noloss, oneloss};
    }
};