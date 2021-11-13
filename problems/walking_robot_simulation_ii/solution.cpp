class Robot {
public:
    int x=1,y=1,x1=0,y1=0,d=0, mxstep=0,m=0,f=0;
    string dir[4]={"East", "North",  "West","South"};
    Robot(int width, int height) {
        x=0,y=0;
        x1=width; y1=height;
        mxstep = (2 * x1 + 2 * y1) -4;         
    }
    
    void move(int num) {

        m = (m + num) % mxstep;
        f=1;
    }
    
    vector<int> getPos() {
        if (m >=0 && m <x1) return {m,0};
        if (m >=x1 && m <x1+y1-1) return {x1-1, m - (x1 - 1) };
        if (m >=x1+y1-1 && m <2 *x1+y1-2) return {(2*x1+y1-3)-m, (y1 - 1) };
        return {0,mxstep - m};
    }
    
    string getDir() {
        
        if(f==0)  return dir[0];
        if (m >=1 && m <x1) return dir[0];
        if (m >=x1 && m <x1+y1-1) return dir[1];
        if (m >=x1+y1-1 && m <2 *x1+y1-2) return dir[2];
        return dir[3];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */