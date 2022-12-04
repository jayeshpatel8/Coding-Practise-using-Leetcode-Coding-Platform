
class Solution {
public:
    int countPalindromes(string s) {
		int mod = 1000000007;		
		int n = s.size();
		long ans = 0;
		int ff[10]={};
		for(int i = 0;i < n;i++){
			long matched = 0;
			for(int j = n-1;j > i;j--){
				if(matched && s[i] == s[j]){
					ans += matched * (j-i-1);
				}
				matched += ff[s[j]-'0'];
				if(matched >= mod)matched -= mod;
			}            
			ff[s[i] - '0']++;
		}
		return (int)(ans % mod);
    }
};