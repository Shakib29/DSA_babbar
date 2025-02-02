//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    static bool cmp(const tuple<double, int, int>& a, const tuple<double, int, int>& b) {
        return get<0>(a) > get<0>(b); // Sort by value/weight in descending order
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<tuple<double, int, int>> items; // (value/weight, value, weight)

        for (int i = 0; i < wt.size(); i++) {
            double perUnitVal = (1.0 * val[i]) / wt[i];
            items.push_back(make_tuple(perUnitVal, val[i], wt[i]));
        }

        sort(items.begin(), items.end(), cmp); // Sort by value/weight

        double totalValue = 0.0;

        for (int i = 0; i < wt.size(); i++) {
            int itemWeight = get<2>(items[i]);
            int itemValue = get<1>(items[i]);
            double itemPerUnitValue = get<0>(items[i]);

            if (itemWeight > capacity) {
                totalValue += capacity * itemPerUnitValue; // Take fraction
                break;
            } else {
                totalValue += itemValue;
                capacity -= itemWeight;
            }
        }

        return totalValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends