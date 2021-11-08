class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        vector<int> sum(l1 + l2);
        for (int i=l1-1; i>=0; i--){
            for (int j=l2-1; j>=0; j--){
                int idx = l1-1-i + l2-1-j;
                int s = sum[idx] + (num1[i]-'0') * (num2[j]-'0');
                sum[idx+1] += s/10;
                sum[idx] = s%10;
            }
        }
        int i = l1 + l2 - 1;
        for (; i>=1 && sum[i]==0; i--) ;
        string ans;
        for (; i>=0 ; i--) 
            ans.push_back(sum[i]+'0');
        return ans;
    }
};