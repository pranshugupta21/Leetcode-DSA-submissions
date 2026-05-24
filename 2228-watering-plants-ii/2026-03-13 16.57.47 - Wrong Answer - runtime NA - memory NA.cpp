class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n= plants.size();
        int ca=capacityA;
        int cb=capacityB;
        int l=0,r=n-1;
        int c=0;
        while(l<r){
            if(plants[l]<=capacityA){
                capacityA-=plants[l];
            }
            else{
                capacityA=ca;
                capacityA-=plants[l];
                c++;
            }
            if(plants[r]<=capacityB){
                capacityB-=plants[r];
            }
            else{
                capacityB=cb;
                capacityB-=plants[r];
                c++;
            }
            l++;
            r--;
        }
        if(l==r){
            if(capacityA>=capacityB ){
                if(capacityA>plants[l]){
                    capacityA-=plants[l];
                }
                else{
                    capacityA=ca;
                    capacityA-=plants[l];
                    c++;
                }
            }
            else{
                if(capacityB>plants[l]){
                    capacityB-=plants[l];
                }
                else{
                    capacityB=cb;
                    capacityB-=plants[l];
                    c++;
                }
              
            }
        }
        
        return c;
    }
};