class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int index=-1;
        int cap=INT_MAX;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                if(capacity[i]<cap){
                  cap=min(cap,capacity[i]);
                  index=i;
                } 
            }
        }
        return index;
    }
};