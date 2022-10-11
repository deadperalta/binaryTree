void preorder(Node* root,int n,int ans)
{
  if(root == NULL || n < 0)
  {
    return;
  }
  
  n--;
  if(n == 0)
  {
    ans=root->val;
  }
  
  preorder(root->left,n,ans);
  preorder(root->right,n,ans);
}

int nthNode(Node* root,int n)
{
  int ans;
  preorder(root,n,ans);
  return ans;
}
