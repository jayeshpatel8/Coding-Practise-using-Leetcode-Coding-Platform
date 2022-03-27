class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int len) {
        long long mp = 9, div=0;
        for (int i=((len+1)/2)-1; i>0; i--)
            mp *=10;
        div = mp/9;
        
        vector<long long>  ans;
        
        for ( auto q : queries){
            if (q > mp) 
                ans.push_back(-1);
            else{
                long long  k = q + div -1, a = k;
                if (len & 1) k/=10;
                for ( ; k>0; k/=10)
                    a = a * 10 + k % 10;

                ans.push_back(a);
            }
        }
        return  ans;
    }
};