class Solution {
public:
    string entityParser(string t) {
        string ans;
        unordered_map<string,char> code;
        code["&quot;"]='"';
        code["&apos;"]='\'';
        code["&amp;"]='&';
        code["&gt;"]='>';
        code["&lt;"]='<';
        code["&frasl;"]='/';
        for ( int i=0, n= t.size(); i<n; i++){
            if (t[i]=='&' && i+4<=n){
                string c;
                c+='&';
                bool found=false;
                for (int j=1; j<7; j++){
                    c +=t[i+j];
                    if (t[i+j] == ';'){                        
                        if (code.count(c)){
                            ans +=code[c];
                            i=i+j;
                            found =true;
                        }
                        break;
                    }
                    
                }
                if (!found)
                    ans += t[i];
            }
            else
                ans += t[i];
        }
        return ans;
    }
};