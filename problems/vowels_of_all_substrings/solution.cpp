class Solution {
public:
    long long countVowels(string word) {
        long long cnt = 0 ,ans = 0;
        int N =word.size();
        
        for (int i=0; i < N; i++)
        {
            if (isvowel(word[i]))
                cnt += (i+1) ;
            ans += cnt; 
        }
        return ans;
    }
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
};