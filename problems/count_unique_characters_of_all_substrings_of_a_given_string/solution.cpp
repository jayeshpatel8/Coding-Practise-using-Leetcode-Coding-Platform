class Solution {
public:
    int uniqueLetterString2(string s) {
        int n = s.size();
        vector<int> last_index(26,-1), contribute(26);
        int ans = 0;
        for (int i=0, cnt = 0; i<n; i++){
             cnt -= contribute[s[i]-'A'];
            contribute[s[i]-'A'] = i - last_index[s[i]-'A'];            
            cnt +=contribute[s[i]-'A'];
            ans +=cnt;
            last_index[s[i]-'A'] = i;
        }
        return ans;
    }
        int uniqueLetterString(string s) {
		int n = s.length();
		vector<int> L(n, -1), R(n, -1);
		vector<int> lastL(26, -1), lastR(26, n);
		for (int i = 0; i < n; i++){
			L[i] = i - lastL[s[i] - 'A'];
			lastL[s[i] - 'A'] = i;
		}     
		for (int i = n-1; i >= 0; i--){
			R[i] = lastR[s[i] - 'A'] - i;
			lastR[s[i] - 'A'] = i;
		}   
		int ans = 0; 

		for (int i = 0; i < n; i++){
			ans += (L[i] * R[i]);
		}
		return ans;
    }
};