class Solution {
public:
    string maxValue(string n, int x) {
        int i=0;
        int c = '0'+ x;
        if (n[i]=='-'){
            for (++i; i<n.size(); i++){
                if (n[i]>c) return n.substr(0,i)+to_string(x)+n.substr(i);
            }   
        }
        else{
            for (; i<n.size(); i++){
                if (n[i]<c) return n.substr(0,i)+to_string(x)+n.substr(i);
            }
        }
        n.push_back(c);
        return n;
    }
};