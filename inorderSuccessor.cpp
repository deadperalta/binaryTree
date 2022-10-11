Node* prev=NULL;
void inorder(Node* root,int x,int &ans)
{
  if(root == NULL)
  {
    return;
  }
  
  inorder(root->left,x,ans);
  if(prev == NULL)
  {
    prev=root;
  }
  if(prev->data == x)
  {
    ans=root->data;
    prev=root;
  }
  inorder(root->right,x,ans);
}

int findSuccessor(Node* root,int x)
{
  int ans=0;
  inorder(root,x,ans);
  return ans;
}
