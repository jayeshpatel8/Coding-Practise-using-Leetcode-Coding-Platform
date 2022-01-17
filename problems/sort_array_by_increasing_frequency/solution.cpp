class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> map[201];
        vector<int> f(201);
        for (auto i : nums)f[i+100]++;
        for (int i=0; i<201; i++){
            if (f[i]){
                map[f[i]].push_back(i);
            }
        }
        vector<int> ans;
        for (int i=1; i<201; i++){
            if (map[i].size()){
                sort(rbegin(map[i]),rend(map[i]));
            }
            for (auto j : map[i]){
                int freq=i;
                while (freq--)
                    ans.push_back(j-100);
            }
        }
        return ans;
    }
};