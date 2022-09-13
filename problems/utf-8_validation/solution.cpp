class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = 0;
        for (auto i : data){
            if (len == 0){
                if (i & 0x80 ){
                    int mask=0x80;
                    while (i & mask) len++,mask >>=1;
                    if (len==1 || len>=5) return false;
                    len--;
                }   
                
            }
            else if ((i & 0x80) == 0 || (i & 0x40)) return false;
            else len--;
        }
        return len==0;
    }
};