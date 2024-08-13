//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

struct deadDesc {
    bool operator()(Job &j1, Job &j2) {
        return j1.dead > j2.dead;
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, deadDesc()); // Sort jobs in desc order of deadlines
        priority_queue<int> pq; // Priority queue of profit values
        int s;
        vector<int> ans = {0, 0}; // number of jobs, maximum profit
        for(int i=0; i<n; i++) {
            if(i == n-1)    s = arr[i].dead;
            else            s = arr[i].dead - arr[i+1].dead;
            pq.push(arr[i].profit);
            while(s>0 && !pq.empty()) {
                ans[0]++;
                ans[1] += pq.top();
                pq.pop();
                s--;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends