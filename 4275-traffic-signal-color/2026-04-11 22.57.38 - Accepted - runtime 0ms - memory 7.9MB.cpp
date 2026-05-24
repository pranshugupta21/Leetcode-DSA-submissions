class Solution {
public:
    string trafficSignal(int t) {
        string s="";
        if(t==0) s+="Green";
        else if(t==30) s+="Orange";
        else if(t>30&&t<=90) s+="Red";
        else s+="Invalid";
        return s;
    }
};