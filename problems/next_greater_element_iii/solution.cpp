class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        for (int i=s.size()-1, j =i;  i>=0; i--){
            if(s[i] < s[j]) {
                sort(s.begin()+j,s.end());
                j = s.size()-1;
                while(i<j){
                    if (s[i] < s[j])
                        j--;
                    else
                        break;
                }
                swap(s[i],s[++j]);
                long ans = stol(s);
                return ans > INT_MAX ? -1 : ans;
            }
            else if (s[i]>=s[j]){
                j  = i;
            }
        }
        return -1;
        
    }
};