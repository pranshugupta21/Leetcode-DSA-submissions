class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,int>freq;
        for(int f:planks){
            freq[f]++;
        }
        vector<pair<int,int>>pairs(freq.begin(),freq.end());
        int n=freq.size();
        for(int i=0;i<n;i++){
            freq[pairs[i].first*2]+=pairs[i].second/2;
            for(int j=i+1;j<n;j++){
                freq[pairs[i].first+pairs[j].first]+=min(pairs[i].second,pairs[j].second);
            }
        }
        int maxwidth=0;
       for(auto &[h,c]:freq){
        maxwidth=max(maxwidth,c);
       }
       return maxwidth;
    }
};