class Solution {
public:
    bool isValid(string s) {
        stack<char> checker;

        for(char c : s){
            if(c == '(' || c == '{' || c == '[') {
                checker.push(c);
            } 
            else {
                if(checker.empty()) return false;

                char x = checker.top();
                checker.pop();

                if(x == '(' && c != ')') return false;
                if(x == '[' && c != ']') return false;
                if(x == '{' && c != '}') return false;
            }
        }

        return checker.empty();
    }
};