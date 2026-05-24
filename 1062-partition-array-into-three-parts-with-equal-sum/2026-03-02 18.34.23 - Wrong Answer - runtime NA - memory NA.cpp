class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int sum1=sum/3;
        int count=3;
        sum=0;
        for(int i=0;i<n;i++){
           sum+=arr[i];
            if(sum==sum1){
                count--;
                sum=0;
            }
        }
        return count==0;
    }
};