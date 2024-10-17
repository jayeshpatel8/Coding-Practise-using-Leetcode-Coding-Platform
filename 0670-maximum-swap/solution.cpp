class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int i,j,k;
        
            for (i=0; i<s.size(); i++){
                if (s[i] != '9') break;
            }
        while(i <s.size()){
            for (j=i,k=j; j<s.size(); j++){
                if (s[k]<= s[j]) k=j;
            }
            if (k <  s.size()){
                if (s[k] == s[i]){
                    i++;
                }
                else{
                    swap(s[i], s[k]);break;
                }
            }
            else break;
        }
        return stoi(s);
    }
};
