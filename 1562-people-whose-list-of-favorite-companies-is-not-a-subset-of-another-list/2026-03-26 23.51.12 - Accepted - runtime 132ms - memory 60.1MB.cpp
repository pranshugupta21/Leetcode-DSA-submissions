class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        
        // Step 1: Sort each person's list of companies alphabetically.
        // This is required to use std::includes efficiently.
        for (int i = 0; i < n; ++i) {
            std::sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }

        std::vector<int> result;

        // Step 2: Compare each person's list against all others
        for (int i = 0; i < n; ++i) {
            bool isSubset = false;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                // Optimization: Person i's list can only be a subset of Person j's 
                // list if i has strictly fewer favorite companies than j.
                if (favoriteCompanies[i].size() < favoriteCompanies[j].size()) {
                    
                    // std::includes returns true if all elements of the second range 
                    // (person i) are contained within the first range (person j)
                    if (std::includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(),
                                      favoriteCompanies[i].begin(), favoriteCompanies[i].end())) {
                        isSubset = true;
                        break; // No need to check other j's, i is already a subset
                    }
                }
            }
            
            // Step 3: If i wasn't a subset of any j, add their index
            if (!isSubset) {
                result.push_back(i);
            }
        }

        return result;
    }
};
