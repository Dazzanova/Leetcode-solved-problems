class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0, minlen = INT_MAX;
        long long sum = 0;
        int n = arr.size();
        vector<int> best(n,INT_MAX);
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            sum += arr[i];

            while(sum > target){
                sum -= arr[l++];
            }

            if(sum == target){
                int len = i - l + 1;

                if(l > 0 && best[l-1] != INT_MAX){
                    ans = min(ans, len + best[l-1]);
                }

                minlen = min(len,minlen);
            }
            best[i] = minlen;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};