class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>nums;
        int temp=n;
        while(temp!=0){
            int ld=temp%10;
             nums.push_back(ld);
             temp/=10;
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=((x*10)+nums[i]);
        }
        if (x==n){
          return -1;
        }
        swap(nums[nums.size()-2],nums[0]);
          int n1=0;
        for(int i=0;i<nums.size();i++){
            n1=((n1*10)+nums[i]);
        }
        int number=0;
        if(n1!=x){
         sort(nums.begin()+1,nums.end());
        }
        
         for(int i=0;i<nums.size();i++){
            number=((number*10)+nums[i]);
        }
        return number;
    }
};