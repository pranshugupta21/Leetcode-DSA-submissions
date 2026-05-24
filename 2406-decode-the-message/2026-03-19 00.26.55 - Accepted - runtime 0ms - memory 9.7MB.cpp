class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> m;
        char c = 'a';
        for(char ch : key){
            if(ch != ' ' && !m.count(ch)){
                m[ch] = c++;
            }
        }
        for(int i = 0; i < message.size(); i++){
            if(message[i] != ' ')
                message[i] = m[message[i]];
        }

        return message;
    }
};