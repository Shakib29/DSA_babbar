//appraoch 1 ,without trie 
//this is better
string longestCommonPrefix(vector<string> &arr, int n) {
 string ans="";
 //for traversing each character of first string
 for(int i=0;i<arr[0].size();i++){
     char ch=arr[0][i];
     bool match="true";

  //for comparingch with rest if the string
  for(int j=1;j<n;j++){
    //not match
    if(arr[j].size()<i||ch!=arr[j][i]){
        match=false;
        break;
    }
  }
  if(match==false){
      break;
  }else{
      ans.push_back(ch);
  }
 }
return ans;
}
