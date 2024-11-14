class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1, r = *max_element(begin(q), end(q));
        
        while(l<r){
            int m = (l + r) / 2;
            
            int rem = n;
            for (auto &q1 : q)
                rem -= q1 / m + (q1 % m ? 1 : 0);
            if (rem >=0)
                r = m ;
            else
                l = m + 1;
        }
        return l ;
    }
};
