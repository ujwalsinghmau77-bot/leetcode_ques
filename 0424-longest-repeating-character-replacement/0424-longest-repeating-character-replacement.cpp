class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        vector<int>freq(26,0);
        int maxi=0;
        int ans=0;
        while(j<n){
            freq[s[j]-'A']++;
            maxi=max(maxi,freq[s[j]-'A']);

            while(j-i+1-maxi>k){
                freq[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};