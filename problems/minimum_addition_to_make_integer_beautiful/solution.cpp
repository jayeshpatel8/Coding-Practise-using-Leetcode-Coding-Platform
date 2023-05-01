class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int sum = 0;
        vector<int> s;
        while(n>0){
            s.push_back(n%10);
            sum+=(n%10);
            n/=10;            
        }
        if (sum <= target) return 0;
        long long ans = 0, mul=1;
        int j=0;
        for (auto i : s){            
            sum -=i+j-1;
            ans += (10-i -j) * mul;
            mul *=10;
            j=1;
 
            if (sum <= target) return ans;
        }

        return 0;
    }
};