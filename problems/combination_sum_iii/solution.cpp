class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        bt(k,n,t);
        return ans;
    }
    void bt(int k, int n, vector<int> & t, int i=1){
        if (k==0 ){
            if (n==0)
                ans.push_back(t);
        }
        else{
            for (; i<10; i++){
                auto rem = n - i;
                if (rem >=0 ){
                    t.push_back(i);
                    bt(k-1,rem,t,i+1);   
                    t.pop_back();
                }
                else
                    break;
            }
        }
    }
};