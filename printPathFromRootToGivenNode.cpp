bool foundPath(Node* root,int x,vector<int>&arr)
{
  if(root == NULL)
  {
    return false;
  }
  
  if(root->data == x)
  {
    arr.push_back(x);
    return true;
  }
  
  arr.push_back(root->data);
  bool left=foundPath(root->left,x,arr);
  
  if(left == true)
  {
    return true;
  }
  
  bool right=foundPath(root->right,x,arr);
  if(right == true)
  {
    return true;
  }
  
  arr.pop_back();
  return false;
}

void printPath(Node* root,int x)
{
  vector<int>arr;
  if(foundPath(root,x,arr) == false)
  {
    cout<<"No Path"<<endl;
  }
  else
  {
    for(int i:arr)
    {
      cout<<i<<" ";
    }
  }
}
  
