//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
      vector<int> meo(vector<int>& left, vector<int>& right) {
        vector<int> ans;
        int l=0, r=0;
        
        while(l<left.size() && r<right.size()) {
            if(left[l]%2!=0 && right[r]%2==0) {
                ans.push_back(left[l]);
                l++;
            }
            else if(left[l]%2==0 && right[r]%2!=0) {
                ans.push_back(right[r]);
                r++;
            }
            else if(left[l]%2!=0 && left[l]>right[r]) {
                ans.push_back(left[l]);
                l++;
            }
            else if(left[l]%2!=0) {
                ans.push_back(right[r]);
                r++;
            }
            else if(left[l]<right[r]) {
                ans.push_back(left[l]);
                l++;
            }
            else {
                ans.push_back(right[r]);
                r++;
            }
        }
        while(l<left.size()) {
            ans.push_back(left[l]);
            l++;
        }
        while(r<right.size()) {
            ans.push_back(right[r]);
            r++;
        }
        return ans;
    }
    
    vector<int> mseo(vector<int>& nums, int l, int r) {
        if(r==l) {
            vector<int> a {nums[l]};
            return a;
        }
        int m = (l+r)/2;
        vector<int> left = mseo(nums, l, m);
        vector<int> right = mseo(nums, m+1, r);
        return meo(left, right);
    }
    void sortIt(long long arr[], long long n) {
        vector<int> nums(arr, arr+n);
        vector<int> ans = mseo(nums, 0, nums.size()-1);
        for(int i=0; i<n; i++) arr[i] = ans[i];
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        Solution ob;
        ob.sortIt(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends