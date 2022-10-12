//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    Node* createTree(int in[],int inStart,int inEnd,int pre[],int preStart,int preEnd,unordered_map<int,int>&inInorder)
    {
        if(inStart > inEnd || preStart > preEnd)
        {
            return NULL;
        }
        
        int dataVal=pre[preStart];
        int inPos=inInorder[dataVal];
        
        int onLeft=inPos-inStart;
        
        Node* root=new Node(dataVal);
        
        root->left=createTree(in,inStart,inPos-1,pre,preStart+1,preStart+onLeft,inInorder);
        root->right=createTree(in,inPos+1,inEnd,pre,preStart+onLeft+1,preEnd,inInorder);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int,int>inInorder;
        
        for(int i=0;i<n;i++)
        {
            inInorder[in[i]]=i;
        }
        
        return createTree(in,0,n-1,pre,0,n-1,inInorder);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
