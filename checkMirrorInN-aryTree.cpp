//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    bool isPal(vector<int>&a)
    {
        int i=0,j=a.size()-1;
        
        while(i < j)
        {
            if(a[i] != a[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,vector<int>>map;
        
        for(int i=0;i<2*e;i+=2)
        {
            map[A[i]].push_back(A[i+1]);
        }
        for(int i=0;i<2*e;i+=2)
        {
            map[B[i]].push_back(B[i+1]);
        }
        
        for(auto it:map)
        {
            if(isPal(it.second) == false)
            {
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends
