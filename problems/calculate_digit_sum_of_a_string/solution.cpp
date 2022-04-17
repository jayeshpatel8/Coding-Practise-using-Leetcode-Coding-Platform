class Solution {
public:
    string digitSum(string s, int k) {
        
        while (s.size() > k){
            
            string s2;
            for (int i=0; i<s.size(); i+=k){
                int j=0;
                for (int c=0; c<k && i+c<s.size(); c++ )
                    j += s[i+c]-'0';
                s2 += to_string(j);
                
            }
            s=s2;
            
        }
        return s;
    }
};