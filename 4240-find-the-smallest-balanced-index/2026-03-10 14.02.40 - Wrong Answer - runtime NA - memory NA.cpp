class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixsum(n+1,0);
        vector<int> prefixmul(n+1,1);
        for(int i=1;i<n+1;i++){
         prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
        prefixmul[i]=prefixmul[i+1]*nums[i];
        }
      int index=INT_MAX;  reverse(prefixmul.begin(),prefixmul.end());
        for(int i=0;i<n;i++){
        if(prefixsum[i]==prefixmul[i]){
            index=min(index,i);
        }
    }
        return index==INT_MAX? -1:index;
    }
};