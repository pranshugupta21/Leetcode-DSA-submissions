class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int> mp;

        // accumulate items1
        for (auto &it : items1) {
            mp[it[0]] += it[1];
        }

        // accumulate items2
        for (auto &it : items2) {
            mp[it[0]] += it[1];
        }

        // convert map to vector
        vector<vector<int>> ans;
        for (auto &p : mp) {
            ans.push_back({p.first, p.second});
        }

        // sort by item value
        sort(ans.begin(), ans.end());
        return ans;
    }
};
