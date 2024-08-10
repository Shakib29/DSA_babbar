#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string>& nums,vector<string> output,int index,vector<vector<string>> &ans){
//base case
if(index>=nums.size()){
   ans.push_back(output);
    return ;
}

//exclude
solve(nums,output,index+1,ans);

//include
string element=nums[index];
output.push_back(element);
solve(nums,output,index+1,ans);




}

vector<vector<string>> subsets(vector<string>& nums){
vector<vector<string>> ans;                                 //final answer
vector<string> output;                                     //{}
int index =0;
solve(nums,output,index,ans);
return ans;
}
int main(){
    vector<string> nums ={"a", "b", "c"};  // Example input
    vector<vector<string>> result = subsets(nums);
    // Print the subsets
    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (string num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;

}