class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low=0,high= max(houses[houses.size()-1],heaters[heaters.size()-1]);
        int maxradius=0;
        while(low<=high){
         int mid=low+(high-low)/2;
         if(canbeinrange(houses,heaters,mid)){
            maxradius=mid;
            high=mid-1;
         }
         else{
            low=mid+1;
         }
        }
        return maxradius;
    }
    private: 
        bool canbeinrange(vector<int>& houses,vector<int>& heaters,int r){
            int i=0,j=0;
            while(i<houses.size()&&j<heaters.size()){
                if(abs(houses[i]-heaters[j])<=r){
                    i++;
                    continue;
                }
                j++;
            }
            return i==houses.size();
        }
};