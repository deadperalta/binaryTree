void fillLeaf(Node* root,vector<int>&a)
{
  if(root == NULL)
  {
    return;
  }
  if(root->left == NULL && root->right == NULL)
  {
    a.push_back(root->data);
  }
  
  fillLeaf(root->left,a);
  fillLeaf(root->right,a);
}
 
bool isSame(Node* a,Node* b)
{
  vector<int>one;
  fillLeaf(a,one);
  
  vector<int>two;
  fillLeaf(b,two);
  
  if(one.size() != two.size())
  {
    return false;
  }
  
  for(int i=0;i<one.size();i++)
  {
    if(one[i] != two[i])
    {
      return false;
    }
  }
  return true;
}
