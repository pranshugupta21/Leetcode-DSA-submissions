class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size() ;
        sort(candyType.begin(), candyType.end()) ;
        int unique = 1 ;
        int curr = candyType[0] ;
        for (int i = 1; i < n; i++){
            if (curr != candyType[i]) {
                curr = candyType[i] ;
                unique++ ;
            }
        }
        return min(n/2, unique);
    }
}; // T.C = O(N*logN) & S.C = O(1)