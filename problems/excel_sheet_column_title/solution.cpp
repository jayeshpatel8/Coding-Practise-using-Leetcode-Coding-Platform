class Solution {
public:
    string convertToTitle(int cn) {
        string ans;
        
        while (cn>0){
            cn-=1;
            auto c = cn%26;
            
            ans.push_back('A' + c );
            //cn-=c;
            cn /=26;
            
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};