

int maxArea(int* height, int heightSize){

    int hmax=0,lmax=0,rmax=0;
    for (int i =0; i < heightSize-1; i++)
    { 
        if (height[i] <= hmax)
            continue;
        int h=0;
         for (int j =heightSize-1; j>i; j--,h++)
         {
             
             int k = height[i]<height[j]?height[i]:height[j];
             if (k*(j-i) > hmax *(rmax-lmax)  ) 
                 lmax = i,rmax=j,hmax=k;
              if (height[i] <= height[j])
                 break;
             
         }
    }
    return (hmax* (rmax-lmax));                   
}

