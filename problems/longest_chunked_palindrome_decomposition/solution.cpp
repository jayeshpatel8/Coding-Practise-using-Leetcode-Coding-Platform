class Solution {
public:
    int longestDecomposition(string text) {
        int i = 0,  j =text.size()-1;
        long m=1e9+7, base2 = 1, pow=1, l=0,r=0 ,ans= 0;
        while(i<=j){
            // aaa  aaaa
            l = (l *26 + (text[i]-'a')+1)%m;
            r = (r  + ((text[j]-'a'+1) * base2))%m;
            base2=(base2 * 26)%m;
            if (l == r ) ans += 1+(i!=j), base2=1,l=r=0;
            i++,j--;
        }
        return ans + (l!=0);
    }
    /*
    int longestDecomposition(string text) {
     int i,i1,j,j1, cnt=0;
        i=i1=0, j=j1=text.size()-1;
        while(i1<j1){
            if (text[i] == text[j1]){
                if (strncmp(&text[i],&text[j1],j-j1+1)==0){
                    cnt+=2; i=i1+1; j=j1-1;
                }
            }
            i1++,j1--;
        }
        if (i<=j) cnt++;
        return cnt;
    }*/
};