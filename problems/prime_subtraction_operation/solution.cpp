class Solution {
public:

    bool primeSubOperation(vector<int>& nums) {
        vector<int> pri ,sieve(1001);
        for (int i=2; i<32; i++){
            if (!sieve[i])
                for (int j=i+i; j<1001; j+=i)
                    sieve[j]=true;
        }
        for (int i=2; i<1001; i++)
            if (!sieve[i])
                pri.push_back(i);

        for (int i=nums.size()-2; i>=0; i--){
            if (nums[i]<nums[i+1]) continue;
            auto it = upper_bound(begin(pri),end(pri),nums[i]-nums[i+1]);
            if (it == end(pri)) return false;
            if (nums[i] - *it <1) return false;
            nums[i] -= *it;
        }
        return true;
    }
};