// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* createTree(int inStart,int inEnd,int in[],int postStart,int postEnd,int post[],unordered_map<int,int>&inInorder)
{
    if(inStart > inEnd || postStart > postEnd)
    {
        return NULL;
    }
    
    int data=post[postEnd];
    
    int pos=inInorder[data];
    
    int space=inEnd-pos;
    
    Node* root=new Node(data);
    
    root->right=createTree(pos+1,inEnd,in,postEnd-space,postEnd-1,post,inInorder);
    root->left=createTree(inStart,pos-1,in,postStart,postEnd-space-1,post,inInorder);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    unordered_map<int,int>inInorder;
    
    for(int i=0;i<n;i++)
    {
        inInorder[in[i]]=i;
    }
    
    return createTree(0,n-1,in,0,n-1,post,inInorder);
}
