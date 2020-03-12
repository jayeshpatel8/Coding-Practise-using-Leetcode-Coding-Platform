class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size()-1,c=1;

        while(n>=0)
        {            
            if (digits[n]==9){
                c = 1;
                digits[n] = 0;                        
            }
            else{digits[n]+=c;c=0;
               break;}
            n--;
        }
        if (c  ) digits.emplace(digits.begin(),c);
        return digits;
    }
};