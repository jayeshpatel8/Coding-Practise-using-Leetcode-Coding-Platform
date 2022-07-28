class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int a[101]={};
        int p=0,np=0;
        for (auto i  : nums)a[i]++;
        for (auto i : a){
            if (i){
                p += i /2;
                np += i&1;
            }
        }
        return {p,np};
     }
};