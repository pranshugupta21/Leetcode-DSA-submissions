class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int finalmax1=nums[n-1]*nums[n-2]*nums[n-3];
        int finalmax2=nums[0]*nums[1]*nums[n-1];
        return max(finalmax1,finalmax2);
      /*  bool first=false;
        if(max1>=max2) first=true;
        max1=max(max1,max2);
        int third=0;
        if(first){
         for(int i=0;i<n;i++){
            if(nums[i]>0){
                third=max(third,nums[i]);
            }
        }
        if(third==0) third=nums[2];
        return max1*third;
        }
        else{
            return max1*nums[n-3];
        }
        */
    }
};