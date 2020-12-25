class Solution {
public:
    string validIPAddress(string IP) {
     int N=IP.length() ;
        if (IP.find('.') != string::npos) 
        {   
            int word=0;
            for (int i=0; i<IP.length();i++ ){
                if (i+1<N && IP[i]=='0' && IP[i+1]!='.' ) return "Neither";
                int sum=0,d=0;
                while (i<N&& IP[i] >= '0'&& IP[i] <='9' && d<4){
                    sum = sum*10 + IP[i]-'0';d++;i++;
                }
                word++;
                if (d>3|| d<1 || (i<N &&( IP[i]!='.' || word >=4)) || sum>255 ) return "Neither";
            }
            if (word <4) return "Neither";
            return "IPv4";
        }
        else if (IP.find(':') != string::npos){
            int word=0;
            for (int i=0; i<N;i++ ){                
                int d=0;
                while (i<N && d<5 && (
                                (IP[i] >= '0'&& IP[i] <='9') ||
                                (IP[i] >= 'a'&& IP[i] <='f') || 
                                (IP[i] >= 'A'&& IP[i] <='F')      
                                    )
                                
                      ){
                    d++;i++;
                }
                word++;
                if (d>4|| d<1 || (i<N &&( IP[i]!=':' || word >=8))  ) return "Neither";
            }
            if (word <8) return "Neither";
                     return "IPv6";
        } 
        
            return "Neither";
    }
};