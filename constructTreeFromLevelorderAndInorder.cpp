// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
int search(vector<int>&in,int i,int j,int x)
{
    int idx=0;
    for(idx=i;idx<j;idx++)
    {
        if(in[idx] == x)
        {
            return idx;
        }
    }
    return idx;
}

vector<int>extract(vector<int>&in,vector<int>&lo,int st,int en)
{
    unordered_map<int,int>m;
    
    for(int i=st;i<=en;i++)
    {
        m[in[i]]++;
    }
    
    vector<int>ans;
    
    for(int i:lo)
    {
        if(m[i])
        {
            ans.push_back(i);
            m[i]--;
        }
    }
    return ans;
}
Node* createTree(vector<int>&in,vector<int>&lo,int is,int ie)
{
    if(is > ie)
    {
        return NULL;
    }
    
    Node* root=new Node(lo[0]);
    
    if(is == ie)
    {
        return root;
    }
    
    int inPos=search(in,is,ie,root->key);
    
    vector<int>left=extract(in,lo,is,inPos-1);
    vector<int>right=extract(in,lo,inPos+1,ie);
    
    root->left=createTree(in,left,is,inPos-1);
    root->right=createTree(in,right,inPos+1,ie);
    
    return root;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    vector<int>in;
    vector<int>lo;
    
    for(int i=0;i<n;i++)
    {
        in.push_back(inorder[i]);
    }
    for(int i=0;i<n;i++)
    {
        lo.push_back(levelOrder[i]);
    }
    
    return createTree(in,lo,iStart,iEnd);
    
}
