    struct cmp{
         bool operator()(pair<int,int> &a , pair<int,int>&b){
          double profita = ((double)a.first+1)  /((double)a.second+1) - ((double)a.first)  /((double)a.second);
            double profitb = ((double)b.first+1)  /((double)b.second+1) - ((double)b.first)  /((double)b.second);
            return profita < profitb;
        }
};
class Solution {

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for (int i=0; i<classes.size(); i++){
            pq.push({classes[i][0],classes[i][1]});      
            
        }
        while(extraStudents--){
            pair<int,int> item = pq.top(); pq.pop();
            ++item.first,++item.second;
            pq.push({item.first,item.second});
        }
        double total;
        while (!pq.empty()){
            pair<int,int> item = pq.top(); pq.pop();
            total += (double)item.first/item.second;
        }
        cout << " ";
        return total/classes.size();
    }
};