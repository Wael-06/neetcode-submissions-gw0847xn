class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq,size=s.size(),l=0,res=0;
        vector<int> f(26, 0);
        for(int i=0;i<size;i++){
            f[s[i]-'A']++;
            maxFreq = max(maxFreq, f[s[i] - 'A']);
            while((i-l+1)-maxFreq>k)f[s[l++]-'A']--;
            res=max(res,i-l+1);
        }
        return res;
    }
};

//maxFreq = max(maxFreq, freq[s[r] - 'A']);