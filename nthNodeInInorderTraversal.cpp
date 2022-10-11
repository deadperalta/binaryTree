void inorder(Node* root,int n,int &ans)
{
  if(root == NULL || n < 0)
  {
    return;
  }
  inorder(root->left,n,ans);
  n--;
  
  if(n == 0)
  {
    ans=root->val;
    return;
  }
  
  if(n > 0)
  {
    inorder(root->right,n,ans);
  }
}

int nThNode(Node* root,int n)
{
  int ans;
  inorder(root,n,ans);
  return ans;
}
