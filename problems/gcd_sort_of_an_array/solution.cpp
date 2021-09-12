class Solution {
public:
    int uf[100001];
    bool gcdSort(vector<int>& nums) {
        vector<int> nums_sorted(nums) ,spf;
        sort(nums_sorted.begin(), nums_sorted.end());        
        memset(uf,-1,sizeof(uf));
        sieve(spf,nums_sorted[nums.size()-1]+1);
        
        for (auto i : nums){
            int n = i;
            while(n>1){
                ufunion(i,spf[n]);
                n/=spf[n];
            }
        }

        for (int i=0;i<nums.size(); i++){
            if (nums[i] != nums_sorted[i] && find(nums[i]) != find(nums_sorted[i])){
                return false;
            }
        }
        return true;
    }
    int find(int i){
        if (uf[i] == -1) return i;
        return uf[i]=find(uf[i]);
    }
    void ufunion(int a, int b){
        
        int pa = find(a), pb = find(b);
        
        if (pa != pb) 
            uf[pa]=pb;
        
        return ;
    }
    void sieve(vector<int>& spf, int n) { 
        spf.resize(n);
        for (int i = 2; i < n; ++i) spf[i] = i;
        for (int i = 2; i * i < n; i++) {
            if (spf[i] != i) continue; // skip if `i` is not a prime number
            for (int j = i * i; j < n; j += i)
                if (spf[j] > i) spf[j] = i; // update to the smallest prime factor of j
        }
    }    
};