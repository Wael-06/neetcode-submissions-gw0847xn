class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        for(char c :s1) freq1[c-'a']++;
        vector<int> freq2(26, 0);
        int l=0,size=s1.size();
        for(int i=0; i<s2.size();i++){
            if(i-l+1>size){
                freq2[s2[l]- 'a']--;
                l++;
            }
            freq2[s2[i]- 'a']++;
            if(freq1==freq2)return true;
        }
        return false;
    }
};
