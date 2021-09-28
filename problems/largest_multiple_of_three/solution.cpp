class Solution {
public:
    
    int freq[10]={};
    string largestMultipleOfThree(vector<int>& digits) {
        
        int sum = 0;
        for (auto i : digits) freq[i]++, sum+=i;        
        if (sum ==0) return "0";
        
        if (sum % 3 !=0){
            if (sum % 3 == 1){
                if (freq[1] || freq[4] || freq[7]){
                    if (freq[1])  freq[1]--;
                    else if (freq[4]) freq[4]--;
                    else freq[7]--;
                }
                else{
                    int cnt=2;
                    for (int i=2; i<=9 && cnt; i+=3){
                        while(cnt >0 && freq[i])
                            freq[i]--,cnt--;
                    }
                }
            }
            else{
                if (freq[2] || freq[5] || freq[8]){
                    if (freq[2])  freq[2]--;
                    else if (freq[5]) freq[5]--;
                    else freq[8]--;
                }  
                else{
                    int cnt=2;
                    for (int i=1; i<=9 && cnt; i+=3){
                        while(cnt >0 && freq[i])
                            freq[i]--,cnt--;
                    }
                }                
            }
        }
        string ans;
        for (int i = 9; i>=0; i--)
            ans += string(freq[i], i+'0');
        
        return ans;
    }

};