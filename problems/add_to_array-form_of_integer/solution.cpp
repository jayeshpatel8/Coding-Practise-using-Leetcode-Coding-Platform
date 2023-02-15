class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int c = 0;
        for (int i=num.size()-1; i>=0 || k>0; i--){

            auto d =  c + k%10;
            if (i>=0) d +=num[i];
            k/=10;
            ans.push_back(d%10);
            c = d/10;
        }
        if (c) ans.push_back(c);
        reverse(begin(ans),end(ans));
        return ans;
    }
};