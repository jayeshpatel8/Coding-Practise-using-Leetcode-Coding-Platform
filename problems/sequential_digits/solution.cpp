class Solution {
public:
    vector<int> dp;
    vector<int> sequentialDigits(int low, int high) {
        string l = to_string(low), h  = to_string(high);
        int sz= l.size();   
        vector<int> ans; 
         string b = "123456789";
        if (dp.size() == 0)
            for ( int len  = 1; len<=9; len++)
                for (int i=0; i<= 9 - len; i++)
                    dp.push_back(mstoi(b.substr(i,len)));

        for (auto n : dp){
            if ( n < low) continue;
            if (n > high) return ans;
            ans.push_back(n);
        }
        
        return ans;
    }
    int mstoi(string  s){
        int ans = 0;
        for (auto c : s){
            ans =  (ans *10) + c - '0';
        }
        return ans;
    }
};