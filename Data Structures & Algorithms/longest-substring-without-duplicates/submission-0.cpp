class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxlen=0,l=0;
        for(int i=0;i<s.size();i++){
            while(mp[s[i]]){
                mp.erase(s[l]);
                l++;
            }
            mp[s[i]]++;
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};
