class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> a,b;
        int n = num;
        while (n>0){
            a.push_back(n%10);
            n/=10;
        }
        b=a;
        int n1=0,n2=0;
        for (int i=a.size()-1, a1=-1; i>=0; i--){            
            if (a1==-1){ 
                if (a[i]==9) continue;
                a1=a[i];
                a[i] = 9;
            }
            else if (a[i]==a1) a[i] = 9;
            //else if (a[i]==9) a[i] = a1;
        }
        for (int i=a.size()-1, a1=-1; i>=0; i--){            
            n1 = n1 * 10 + a[i];
        }
        for (int i=a.size()-1, a1=-1; i>=0; i--){            
            if (a1==-1){ 
                if (a[i]==0) continue;
                a1=b[i];
                b[i] = 0;
            }
            else if (b[i]==a1) b[i] = 0;
          //  else if (a[i]==0) a[i] = a1;
        }
        for (int i=a.size()-1, a1=-1; i>=0; i--){            
            n2 = n2 * 10 + b[i];
        }
        cout << n1 << " " << n2;
        return n1-n2;
    }
};