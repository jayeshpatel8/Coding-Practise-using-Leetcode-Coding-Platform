class Solution {
public:
const int MAXN = 1e5 + 1, MOD = 1e9 + 7;
int sumOfFlooredPairs(vector<int>& nums) {
	vector<long> freq(2*MAXN+1);        
	long mx = 0, sum = 0, prev=0,prevsum=0;
	for(auto num : nums) ++freq[num], mx = max((int)mx, num);  
	for(int i = 1; i <= 2*MAXN; ++i) freq[i] += freq[i - 1];   
    int k=0;
	for(auto num : nums) { 
        if (num == prev) {
            sum = (sum + prevsum)%MOD;continue;
        }
		long l = num, r = 2 * num - 1, divResult = 1,s = 0;
		while(l <= mx) {                
			s = (s + divResult * (freq[r] - freq[l - 1])) % MOD;
			l += num, r += num;
			++divResult;
		}
        sum = (sum + s) %MOD;
        prevsum=s;
        prev=num;
	}
	return sum;
}

};