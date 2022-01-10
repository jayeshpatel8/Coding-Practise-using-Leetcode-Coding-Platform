class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0,i =a.size()-1, j=b.size()-1;
        string ans;
        while (i >=0 || j>=0 || c){
            c += (i>=0? a[i--]-'0' :  0 )+ (j>=0 ? b[j--]-'0' : 0 );
            ans += (c& 1)+'0';
            c = c>1;        
        }    

        reverse(begin(ans), end(ans));
        return ans;
    }
};