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
                c++;
            }
            if(plants[r]<=capacityB){
                capacityB-=plants[r];
            }
            else{
                capacityB=cb;
                c++;
            }
            l++;
            r--;
        }
        if(l==r){
            if(capacityA>capacityB){
                capacityA-=plants[l];
            }
            else if(capacityA<capacityB){
                capacityB-=plants[l];
            }
            else{
                capacityA-=plants[l];
                c++;
            }
        }
        
        return c;
    }
};