class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        for (int i=0, j=0, N1 = v1.size(), N2 = v2.size(); i<N1 || j<N2;){
            int a=0,b=0;
            while (i<N1 && v1[i] == '0'){
                i++; continue;
            }
            while (i<N1 && v1[i] != '.')
                a = a*10 + v1[i++]-'0';
            
            
            while (j<N2 && v2[j] == '0'){
                j++; continue;
            }
            while (j<N2 && v2[j] != '.')
                b = b*10 + v2[j++]-'0';
            
                        
            if (a != b){
                return a < b? -1 : 1;
            }
            j++;i++;
        }
        return 0;
    }
};