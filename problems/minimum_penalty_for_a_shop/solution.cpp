class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> no(customers.size()+1), yes(no);
        
        for (int i=customers.size()-1,cnt=0; i>=0; i--)
            yes[i] = (cnt += customers[i]=='Y');
        for (int i=0,cnt=0; i<customers.size(); i++)
            no[i] = (cnt += customers[i]=='N');
        int ans= 0, p=INT_MAX;
        for (int i=0; i<=customers.size(); i++){
            auto pen = (i> 0 ? no[i-1] : 0 ) + yes[i];
            if (pen < p){
                ans = i;
                p=pen;
            }
        }
        return ans;
    }
};