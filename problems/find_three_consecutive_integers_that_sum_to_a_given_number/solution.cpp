class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        unsigned long long m;
        if(num %3) return {};
        
       
        m = num/3;
        if ((m + m + m) == num)
            return {(long long)(m-1),(long long)m,(long long)(m+1)};
        else
            return {};
    }
};