bool findPath(Node* root,vector<int>&v,int i)
{
  if(i == v.size())
  {
    return true;
  }
  if(root == NULL)
  {
    return false;
  }
  if(v[i] != root->data)
  {
    return false;
  }
  
  return findPath(root->left,v,i+1) and findPath(root->right,v,i+1);
}
  
bool isPathThere(Node* root,vector<int>&v)
{
  return findPath(root,v,0);
}
