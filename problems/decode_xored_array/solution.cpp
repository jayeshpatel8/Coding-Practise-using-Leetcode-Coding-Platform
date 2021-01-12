class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
         vector<int> res(encoded.size()+1);
        int next =first;
        int l=0;
        res[l++]=next;
         for (auto i : encoded)
         {
             next ^= i;
             res[l++]=next;
         }
        return res;
    }
};