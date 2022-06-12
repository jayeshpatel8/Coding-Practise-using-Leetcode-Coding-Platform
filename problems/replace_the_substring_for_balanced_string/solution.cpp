class Solution {
public:
    int balancedString(string s) {
        int f[128]={}, ans = INT_MAX, N = s.size(), cnt = N/4;
        for (int r=0; r< N; r++){
            f[s[r]]++;
        }

        if (f['Q']==cnt && f['E']==cnt && f['R']==cnt) return 0;

        for (int l = 0, r=0; r< N; r++){
            f[s[r]]--;
            while (l <=r && f['Q'] <= cnt && f['E'] <= cnt && f['R'] <= cnt && f['W'] <= cnt){
                ans = min(ans, r-l+1);
                f[s[l++]]++;
            }
            
        }
        return ans;
    }

};