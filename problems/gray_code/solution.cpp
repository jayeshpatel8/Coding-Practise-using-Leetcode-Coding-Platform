class Solution {
public:
    vector<int> grayCode(int n) {
   
        vector<int> res;
        res.push_back(0);
        int i=1;
        int max=pow(2,n);
        for (;i<max; i++){
            
            res.push_back(i^(i/2));
        }
      
        return res;
    }
};