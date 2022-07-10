class Solution {
public:
    int fillCups(vector<int>& amount) {
        int a=amount[0],b=amount[1],c=amount[2],s=0;
        priority_queue<int> pq(begin(amount),end(amount));
        for(;  !pq.empty(); ){
            int a= 0 ,b = 0;
            if (!pq.empty()) {
                a= pq.top(); pq.pop();
            }
            if (!pq.empty()) {
                b= pq.top(); pq.pop();
            }
            if (b==0){
                s+=a; break;
            }
            else{
                s++;
                if (a > 0)
                pq.push(a-1);
                if (b > 0)
                pq.push(b-1);
                //cout << a -1 << " " << b-1 <<endl;
            }
        }
        return s;
    }
};