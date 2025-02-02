class Solution {
public:
int solveopt(string text1, string text2){
  
    int n=text1.size();
    int m=text2.size();
     vector<int> curr(m+1,0);
     vector<int> next(m+1,0);
      for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
              int length=0;
           //match
        if(text1[i]==text2[j]){
            length=1+next[j+1];
        }else{
            length= max(next[j],curr[j+1]);
        }
         curr[j]=length;  
        }
        next=curr;
      }
      return next[0];
   }


    int longestPalindromeSubseq(string s) {
        string rev_str=s;
        reverse(rev_str.begin(),rev_str.end());
        return solveopt(s,rev_str);
    }
};  