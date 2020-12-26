class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        int  end=0;
        double time=0;
        
        for (auto i : cus){
            

            end = max (end, i[0]) + i[1];
            time += (end - i[0]);      
            
        }
        return time/cus.size();
    }
};