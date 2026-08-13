class Solution {
public:                             // Good Question
    int maxProfit(vector<int>& inventory, int orders) {
        int n=inventory.size();
        long long mod=1e9+7;
        long long total_profit=0;
        
        auto ball_sold=[&](long long t){
            long long c=0;
          for(int x:inventory){
            if(x>t){
             c+=x-t;
            }
          }
          return c;
        };
        long long low=0,high=*max_element(inventory.begin(),inventory.end());
        long long threshold=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(ball_sold(mid)<=orders){
                threshold=mid;
                high=mid-1;          // lower the threshold
            }
            else{
                low=mid+1;
            }
        }
        long long total_count=0;
        for(auto x:inventory){
            if(x>threshold){
                long long ball_count=x-threshold;
                long long sum_per_colour=(x+threshold+1)*ball_count/2;
                total_profit=(total_profit+(sum_per_colour))%mod;     // per ball profit
                total_count+=ball_count;
            }
        }
        long long leftover=orders-total_count;
         total_profit=(total_profit+(threshold*leftover))%mod;
        return total_profit;
        }
};