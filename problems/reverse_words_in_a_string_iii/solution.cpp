class Solution {
public:
    string reverseWords(string s) {
     int i=0 ,j =0, N= s.size();
        for (; i<N; i++){
            if (s[i] == ' ') {
                reverse(s,j,i-1);
                j=i+1;
            }            
        }    
        if (i-j>1) reverse(s,j,i-1);
        return s;
    }
    void reverse(string & s, int i, int j){
        while (i<j)
            swap(s[i++],s[j--]);
    }
};