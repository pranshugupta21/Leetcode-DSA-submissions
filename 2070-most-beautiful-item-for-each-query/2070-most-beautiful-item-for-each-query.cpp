class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       sort(items.begin(), items.end());
        
        // 2. Pass through and update beauty to be the "prefix maximum" beauty
        int max_beauty_so_far = 0;
        for (int i = 0; i < items.size(); i++) {
            max_beauty_so_far = max(max_beauty_so_far, items[i][1]);
            items[i][1] = max_beauty_so_far; 
        }
        
        vector<int> res;
        int n=items.size();
        // 3. Process each query using binary search
        for (int q : queries) {
           int low=0,high=n-1,ans=-1;
           while(low<=high){
            int mid=low+(high-low)/2;
            if(items[mid][0]<=q){
                ans=items[mid][1];
                low=mid+1;

            }
            else{
                high=mid-1;
            }
           }
           if(ans==-1) res.push_back(0);
           else res.push_back(ans);
        }
        
        return res;
    }
};