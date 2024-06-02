class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i=0 , j=s.size()-1; i<j;j--, i++){
            swap(s[i] , s[j]) ;
        }   
        return ;
    }
};
