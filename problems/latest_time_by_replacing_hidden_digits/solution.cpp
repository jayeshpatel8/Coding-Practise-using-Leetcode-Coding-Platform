class Solution {
public:
    string maximumTime(string t) {
        if (t[0]=='?' || t[1]=='?'){
            if (t[0]=='?' &&  t[1]=='?') t[0]='2',t[1]='3';
            else if (t[0]=='?'){
                t[0]='1' + (t[1]<'4');
            }
            else{
                if (t[0]<'2') t[1]='9';
                else  t[1]='3';
            }
        }
        if (t[3]=='?' || t[4]=='?'){
            if (t[3]=='?' &&  t[4]=='?') t[3]='5',t[4]='9';
            else if (t[3]=='?'){
                t[3]='5';
            }
            else{
                t[4]='9';
            }
        }
        return t;
    }
};