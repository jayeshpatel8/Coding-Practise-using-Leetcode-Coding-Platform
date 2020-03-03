class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < 1|| num2.size() <1) return "0";

        int s1 =num1.size(),s2=num2.size();
        vector<int> arr(s1+s2,0);
        for (int i=s1-1; i>=0;i--)
        {
            for (int j=s2-1; j>=0 ;j--)
            {                   
                int p = s1 -i-1 +s2 -j-1;
                int sum  = (num2[j]-'0')*(num1[i]-'0')+arr[p];  
                arr[p+1] += sum/10;
                arr[p] = sum%10;                  
            }            
        }

        int i=s1+s2-1;        
        while (i && arr[i]==0)
            i--;
        string r("");
        while (i>=0){
            r +=(arr[i--]+'0');            
        }
        return r;
    }
};