class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        while (n>1){
            ans.push_back(n);
            ans.push_back(-n);
            n-=2;
        }
        if (n> 0) ans.push_back(0);
        return ans;

    }
};
