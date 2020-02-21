

void _generateParenthesis(vector<string> &r,char * arr,int n, int open,int close){

        if (close >= n)
        {
            r.push_back(arr);
            return;
        }
        if (open<n){
            arr[open+close]='(';
            _generateParenthesis(r,arr,n, open+1,close);        
        }
        if (close<open){
            arr[open+close]=')';
            _generateParenthesis(r,arr,n, open,close+1);        
        }                
}




class Solution {
public:
    vector<string> generateParenthesis(int n) {
    
        vector<string> r;// = new vector<string>;
        if (n <= 0)  return r;
        
        char arr[n*2+1]={'\0'};
        _generateParenthesis(r,arr,n,0,0);
        return r;
        
    }
};

