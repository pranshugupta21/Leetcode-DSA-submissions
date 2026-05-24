class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int cap=INT_MAX;
        int in=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity [i]>=itemSize){
                if(cap>capacity[i]){
                    cap=min(cap, capacity[i]);
                    in=i;
                }
            }
        }
        return in;
    }
};