class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int>  ans;
        unordered_map<int,int> mask;
        for ( auto w : words){
            int m = 0;
            for (auto c : w)
                m |= 1 << (c - 'a');
            mask[m]++;
        }
        for (auto p : puzzles){
            int m = 0;
            for (auto c : p)
                m |= 1 << (c - 'a');            
            int cnt = 0 ,reqd_bit = (1<<(p[0]-'a'));;
            for (int sub_mask = m; sub_mask; sub_mask = (sub_mask -1) & m){
                if (sub_mask & reqd_bit )
                    cnt+=mask[sub_mask];
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};