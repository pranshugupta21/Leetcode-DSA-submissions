class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(),inventory.rend());
        inventory.push_back(0);
        int n=inventory.size();
        long long mod=1e9+7;
        long long total_profit=0;
        for(int i=0;i<n-1;i++){
         long long k=i+1;
         long long h=inventory[i];
         long long l=inventory[i+1];
         if(h==l)continue;
         long long count=k*(h-l);
         if(orders>=count){
            long long per_order_sum=(h+l+1)*(h-l)/2;
            total_profit=(total_profit+(k*per_order_sum))%mod;
            orders-=count;
         }
         else{
            long long drops=orders/k;
            long long rem=orders%k;
            long long per_order_sum=((2*h-drops+1)*(drops))/2;
            total_profit=(total_profit+(k*per_order_sum))%mod;
            // remaining
            total_profit=(total_profit+(rem*(h-drops)))%mod;
            orders=0;
            break;

         }
        }
        return total_profit;
    }
};