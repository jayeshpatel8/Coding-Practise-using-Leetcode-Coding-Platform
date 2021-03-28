class Solution {
public:
    void cal(int c, int d,int * ch ,int * digits, string * str){
        if (ch[c-'a']){
            int n = ch[c-'a'];
            digits[d] = n;
            for (auto c : str[d]) ch[c-'a'] -=n;
        }
    }
    string originalDigits(string s) {
        /* 0 - zero z
            6 six  x
            2- two  w
            4 four  u
            8 eight  g
            
            3 three         t             
            1- one            o              
            
            5 five            f
            7 seven s
            
            9 nine
            
        */
        int ch[26]={};
        for (auto c : s) ch[c-'a']++;
        string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
        int digits[10]={};
        
        
        // z
        //cal('z', 0, ch ,digits,str); 
        digits[0] = ch [ 'z'-'a'];
        // x
        //cal('x', 6, ch ,digits,str); 
        digits[6] = ch [ 'x'-'a'];
        
        //w
        //cal('w', 2, ch ,digits,str);
        digits[2] = ch [ 'w'-'a'];
        // u
        //cal('u', 4, ch ,digits,str);
        digits[4] = ch [ 'u'-'a'];
        // g
        //cal('g', 8, ch ,digits,str);
        digits[8] = ch [ 'g'-'a']; 
        // t
        //cal('t', 3, ch ,digits,str);
        digits[3] = ch [ 'h'-'a'] - digits[8];
        // o
        //cal('o', 1, ch ,digits,str);
        digits[1] = ch [ 'o'-'a'] - digits[0]- digits[2]- digits[4];
        // 5 five            f
        //cal('f', 5, ch ,digits,str);
        digits[5] = ch [ 'f'-'a'] - digits[4];
        //7 seven s
        //cal('s', 7, ch ,digits,str);
        digits[7] = ch [ 's'-'a'] - digits[6];
        //9 nine        
        //cal('n', 9, ch ,digits,str);
        digits[9] = ch [ 'i'-'a'] - digits[5]- digits[6]- digits[8];
        string ans;
        for (int i=0; i<10; i++){
            char s = '0' + i;
            
            while(digits[i]--)
                ans +=s;
        }
        return ans;
    }
};