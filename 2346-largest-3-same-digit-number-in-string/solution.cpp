class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=0;
        for (int i=1 ,c=0; i<num.size(); i++){
            if (num[i] == num[i-1]){
                if (c==1) {
                    ans=max<int>(ans, num[i]);
                }
                else c=1;
            }
            else
            c=0;
        }
        return ans==0 ? "" : string(3,ans);
    }
};
