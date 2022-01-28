class Cashier {
public:
    int prd[201]={};
    int N , dis, cust=0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
         N = n , dis = discount;
        for (int i=0;i<products.size(); i++){
            prd[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        int total = 0;
        
        for (int i=0;i<product.size(); i++){
            total +=  prd[product[i]]* amount[i];
        }
        if (++cust%N == 0){
           return (total) * ((100 - (double)dis)/ 100);
        }
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */