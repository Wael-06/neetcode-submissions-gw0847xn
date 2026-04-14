class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int>m(26,0);
        for(char c:s){
            m[c-'a']++;
        }
        for(char c:t){
            m[c-'a']--;
        }
        for(int x:m){
            if(x!=0)return false;
        }return true;
    }
};
