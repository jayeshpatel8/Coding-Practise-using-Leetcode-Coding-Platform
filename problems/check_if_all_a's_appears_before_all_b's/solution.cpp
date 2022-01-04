class Solution {
public:
    bool checkString(string s) {
        int b=0;
        for (auto c : s){
            if (c == 'a' ) {
                if (b) 
                    return false;
            }
            else b++;
        }
        return true;
    }
};