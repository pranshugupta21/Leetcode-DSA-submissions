class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        vector<unordered_set<string>>v(n);
        for(int i=0;i<n;i++){
            for(auto word:favoriteCompanies[i]){
                v[i].insert(word);
            }
        }
        vector<int>res;
        for (int i = 0; i < n; ++i) {
            bool issubset=false;
           for(int j=0;j<n;j++){
            if(i==j) continue;
            if(favoriteCompanies[i].size()<favoriteCompanies[j].size()){
                bool currsubset=true;
                for(auto word:favoriteCompanies[i]){
                    if(v[j].find(word)==v[j].end()){
                        currsubset=false;
                        break;
                    }
                }
                if(currsubset){
                    issubset=true;
                    break;
                }
            }
           }
           if(!issubset){
            res.push_back(i);
           }
        }
        return res;
    }
};
