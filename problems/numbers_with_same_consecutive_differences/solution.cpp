class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans(9) ;
        iota(begin(ans), end(ans),1);
        

        while (n-- >= 2){
            vector<int> ans2;
            for (auto num : ans){
                int i = num % 10;
                if (i+k < 10)
                    ans2.push_back(num * 10 + i + k);
                
                if (k >0 && i-k>=0)
                    ans2.push_back(num * 10 + i - k);                
            }
            ans.swap(ans2);
        }
        return vector<int>(begin(ans),end(ans));
    }
};