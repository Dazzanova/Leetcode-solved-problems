class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> mp;

        for(auto &v : k) mp[v[0]] = v[1];

        string ans;
        int i = 0;

        while(i < s.size()) {
            if(s[i] != '(') {
                ans += s[i];
                i++;
                continue;
            }

            int j = i + 1;

            while(s[j] != ')')
                j++;

            string key = s.substr(i + 1, j - i - 1);

            if(mp.count(key))
                ans += mp[key];
            else
                ans += "?";

            i = j + 1;
        }
        return ans;
    }
};
