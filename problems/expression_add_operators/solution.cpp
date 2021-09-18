class Solution {
public:
    vector<string> ans;
    int target;
    vector<string> addOperators(string num, int t) {
        target =t;

        add(num,"",0,0,0);
        
        return ans;
    }
    vector<string> expressions;
    void add(string &num ,string s, int i, long int prev, long res){
        if (i==num.size() and res == target){
            ans.push_back(s); 
            return ;
        }            
        string s1;
        long int n = 0;

            
        for ( int j = i; j<num.size(); j++){
            
            s1 +=num[j];
            n = n * 10 + num[j]-'0';
            if(s1.size()>1 && s1[0]=='0') break;
            
            if (i==0)
                add(num,s1,j+1, n,n);                            
            else{
                add(num,s +"+"+s1,j+1, n,res+n);
                add(num,s +"-"+s1,j+1, -n,res - n);
                add(num,s +"*"+s1,j+1, prev * n,res-prev + (prev * n));
            }
        }        
    }
        
};