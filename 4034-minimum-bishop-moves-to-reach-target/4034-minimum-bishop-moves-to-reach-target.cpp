class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x1,y1,x2,y2;
       x1= source[0];
        y1=source[1];
        x2=target[0];
        y2=target[1];
        if(abs(x1-x2)==abs(y1-y2)) return 1; // distance travelled by both cells are same so on a right track
        else if((x1+y1)%2==(x2+y2)%2) return 2;
        return -1;
    }
};