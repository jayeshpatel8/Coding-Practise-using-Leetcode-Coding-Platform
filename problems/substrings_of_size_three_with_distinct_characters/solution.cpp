class Solution {
public:
    int countGoodSubstrings(string s) {
        int map[256]={};
        int ans=0;
        //"xyzzaz"
        // yyz
        int cnt=0, j=0;
        for (int i=0; i<s.length(); i++){
            int c  = s[i];
            if(map[c]!=0){                
                while(map[c]>0){
                     map[s[j++]]--;
                }
             
            }

                map[c]=1;
                

            if (i-j == 2) ans++,map[s[j++]]--;;
        }
        return ans;
    }
};