class Solution {
public:
    int addMinimum(string word) {
        string s= "abc";
        int ans = 0,j=0;
        for (int i=0; i<word.size();){
            while (s[j] != word[i]){
                ans++, j =  (j+1)%3;
            }
            i++; j =  (j+1)%3;
        }
        if (j)
            ans  += 3-j;
        return ans;
    }
};