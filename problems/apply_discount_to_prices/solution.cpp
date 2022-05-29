class Solution {
public:
    string discountPrices(string s, int d) {
        string ans;
        for (int i=0,N=s.size(); i<N; i++){

                ans+=s[i];
                if (s[i] == '$' && i+1 <N && isdigit(s[i+1]) ){
                    if (i-1 >= 0 && s[i-1] != ' ') continue;
                    int j = i+1;
                    unsigned long long n1=0;

                    while (j < N && isdigit(s[j])){
                        n1 = n1 * 10 + (s[j++]-'0');
                    }
                    if (j<N && s[j] != ' ') continue;
                    
                    double  p = (double)n1 * (100-d) / 100;
                    string a = to_string(p + 0.005);
                    {
                        int sz= a.size();
                        
                        for (int i=sz-1; a[i-2] != '.';i--)
                            a.pop_back();
                        
                        ans +=a;
                    }
                    i=j-1;
                }

        }
        return ans;
    }
};