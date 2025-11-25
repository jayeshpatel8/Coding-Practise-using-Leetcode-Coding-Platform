class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0) return -1;
        vector<bool> seen(k);
        for ( int rem=0, len=1; len  <=k; len++){
            if ( (rem = (rem *10 +1 ) % k )== 0) // (a*10 + 1)%k => ((a%10)%k + 1%k)%k
                return len;
            if(seen[rem]) return -1; 
            seen[rem]=true;
        }
        return -1;
    }
};
