//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int n = id.size();
        vector<tuple<int, int, int>> jobs;
        
        for (int i = 0; i < n; i++) {
           jobs.push_back(std::make_tuple(profit[i], deadline[i], id[i]));

        }
        
        sort(jobs.rbegin(), jobs.rend());
        
        int maxiDeadline = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxiDeadline = max(maxiDeadline, get<1>(jobs[i]));
        }
        
        vector<int> schedule(maxiDeadline + 1, -1);
        int count = 0, maxProfit = 0;
        
        for (int i = 0; i < n; i++) {
            int currProfit = get<0>(jobs[i]);
            int currDead = get<1>(jobs[i]);
            int currJobID = get<2>(jobs[i]);
            
            for (int k = currDead; k > 0; k--) {
                if (schedule[k] == -1) {
                    count++;
                    maxProfit += currProfit;
                    schedule[k] = currJobID;
                    break;
                }
            }
        }
        
    return {count, maxProfit};
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends