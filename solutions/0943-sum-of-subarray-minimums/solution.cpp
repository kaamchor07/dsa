class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s;
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            left[i]=s.empty() ? (i+1) : (i-s.top()); 
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            right[i]=s.empty() ? (n-i) : (s.top()-i); 
            s.push(i);
        }
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long temp=(1LL*left[i]*right[i])%mod;
            long long contri=(temp*arr[i])%mod;
            ans=(ans+contri)%mod;
        }
        return ans;
    }
};
