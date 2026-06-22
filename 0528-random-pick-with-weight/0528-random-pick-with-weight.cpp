class Solution {
public:
 
   vector<int>wt;
    Solution(vector<int>& w) {
        wt.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            wt.push_back(wt.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int random=rand()%wt.back();
        int idx=upper_bound(wt.begin(),wt.end(),random)-wt.begin();
        return idx;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */