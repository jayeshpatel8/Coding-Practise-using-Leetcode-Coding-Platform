class Solution {
public:
    int sum(string s){
        int sum=0;
       // for (int j=s.size()-1;j>=0;j--) 
        for (auto c : s) {sum +=(c-'a'); sum*=10;}
        //cout << sum << endl;
        return sum/10;
    }
    bool isSumEqual(string f, string s, string t) {
        //cout << sum(f) << "  " <<  sum(s) << " " << sum(t) <<endl;
        return (sum(f) + sum(s)) == sum(t);
    }
};