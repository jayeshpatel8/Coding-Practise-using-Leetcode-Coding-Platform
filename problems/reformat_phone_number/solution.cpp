class Solution {
public:
    string reformatNumber(string number) {
        vector<int> c;
        
        for (auto ch : number){
            if (isdigit(ch)) c.push_back(ch);
        }
        int n = c.size();
        if (n <2) return "";
        
        string res;
        int i=0;
        if (n>4 && n%3 == 0) {
            int n3 = n>4? (n)/3:0;
            for (; i<(n3*3); ){
                res.push_back((c[i++]));
                res.push_back((c[i++]));
                res.push_back((c[i++]));
                if (i<n-1)
                    res.push_back('-');
            }

        }
        else{
            int n3 = n>4? (n-2)/3:0;
            for (; i<(n3*3); i+=3){
                res.push_back((c[i]));
                res.push_back((c[i +1]));
                res.push_back((c[(i) +2]));
                if (i<n-1)
                    res.push_back('-');
            }            
        if (n-i ==4){
            res.push_back((c[n-4]));
            res.push_back((c[n-3]));
            res.push_back('-');        
            res.push_back((c[n-2]));
            res.push_back((c[n-1]));
        }
        else if ((n-i ==3)){
            res.push_back((c[n-3]));
            res.push_back((c[n-2]));
            res.push_back((c[n-1]));            
        }
        else {
            res.push_back((c[n-2]));
            res.push_back((c[n-1]));                        
        }
        }
        return res;
    }
};