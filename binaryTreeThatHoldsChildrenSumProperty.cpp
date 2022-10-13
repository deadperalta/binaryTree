void increment(Node* root,int x)
{
  if(root->left)
  {
    root->left+=x;
    increment(root->left,x);
  }
  else if(root->right)
  {
    root->right+=x;
    increment(root->right,x);
  }
}

void childSum(Node* root)
{
  if(root == NULL || (root->left == NULL && root->right == NULL))
  {
    return;
  }
  
  childSum(root->left);
  childSum(root->right);
  
  int leftData=0,rightData=0;
  
  if(root->left)
  {
    leftData=root->left->data;
  }
  if(root->right)
  {
    rightData=root->right->data;
  }
  
  int diff=root->data-leftData-rightData;
  
  if(diff > 0)
  {
    root->data+=diff;
  }
  else if(diff < 0)
  {
    increment(root,-diff);
  }
}

void convert(Node* root)
{
  childSum(root);
}
