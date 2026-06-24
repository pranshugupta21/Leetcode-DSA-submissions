class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long>ans;
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
         for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
         }
         for(auto &q:queries){
            auto it=lower_bound(nums.begin(),nums.end(),q)-nums.begin();
            long long no_of_left_elements=-1,no_of_right_elements=-1;
            long long rsum=0,msum=0,lsum=0;
            if(it>n-1){
              no_of_right_elements=0;
              rsum=0;
              msum=0;
            }
            else {
            no_of_right_elements=n-it-1;
            rsum=abs((no_of_right_elements*q)-(prefix[n-1]-prefix[it]));
            msum=(abs(nums[it]-q));
            }
            no_of_left_elements=it;
            if(it==0){
            lsum=0;
            }
            else{
                lsum=abs((no_of_left_elements*q)-(prefix[it-1]));
            }
            
            long long num=lsum+msum+rsum;
            ans.push_back(num);
         }

        return ans;
    }
};