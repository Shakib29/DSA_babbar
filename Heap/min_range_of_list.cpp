#include <limits.h>
#include <queue>
#include <vector>
#include<iostream>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;  // Min-heap based on data value
    }
};

int kSorted(vector<vector<int>>& a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    // Min-heap to store the smallest elements from each row
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Insert the first element of each row into the min-heap
    for (int i = 0; i < k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    // Start with the current smallest range
    int start = mini, end = maxi;

    // Process the elements in the heap
    while (!minHeap.empty()) {
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;  // Current minimum from the heap

        // Update the range if a smaller range is found
        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // Move to the next element in the current row
        if (temp->col + 1 < a[temp->row].size()) {  // Corrected condition  xx
            int nextElement = a[temp->row][temp->col + 1];
            maxi = max(maxi, nextElement);  // Update the maximum value
            minHeap.push(new node(nextElement, temp->row, temp->col + 1));
        } else {
            // If we reach the end of one list, stop the process
            break;
        }
    }

    // Return the length of the smallest range found
    return (end - start + 1);
}

int main() {
    vector<vector<int>> a = {{3, 2}, {2, 4, 5}};
    int k = 2;
    int n = 2; // Number of elements per row
    int result = kSorted(a, k, n);
   cout<<result;
    return 0;
}
