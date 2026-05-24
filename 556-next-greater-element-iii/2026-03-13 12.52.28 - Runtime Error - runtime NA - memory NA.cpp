class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>nums;
        int temp=n;
        while(temp!=0){
            int ld=temp%10;
             nums.push_back(ld);
             temp/=10;
        }sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=((x*10)+nums[i]);
        }
        if (x==n){
          return -1;
        }
        int s=nums.size();
        int y=n;
        int i=0;
        while(y!=0){
            int ld=y%10;
            nums[i]=ld;
             y/=10;
             i++;
        }
        reverse(nums.begin(),nums.end());
        int idx=-1;
        int n1=-1;
        for(int i=s-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
              idx=i;
            n1=nums[i];
            break;
            } 
        }
        for(int i=s-1;i>=0;i--){
            if(nums[i]>nums[idx]){
            swap(nums[i],nums[idx]);
            break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());
        int x1=0;
        for(int i=0;i<nums.size();i++){
            x1=((x1*10)+nums[i]);
        }
        return x1;
    }
};