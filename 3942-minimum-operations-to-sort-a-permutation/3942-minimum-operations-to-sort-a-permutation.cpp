
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int zero_idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero_idx=i;
                break;
            }
        }
        bool ascend=true;
        for(int i=0;i<n;i++){
            if(nums[(zero_idx+i)%n]!=i){
                ascend=false;
                break;
            }
        }
        if(ascend){
            if(zero_idx==0)return 0;
            return min(zero_idx,2+n-zero_idx);
        }
        bool decend=true;
        for(int i=0;i<n;i++){
            if(nums[(zero_idx+i)%n]!=(n-i)%n){
                decend=false;
                break;
            }
        }
        if(decend){
            return min((1+(zero_idx+1)%n),n-zero_idx);
        }
        return -1;
    }
};
