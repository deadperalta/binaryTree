Node* reverse(Node* root,map<int,int>&mark,int x,int &nextPos,int &level)
{
  if(root == NULL)
  {
    return NULL;
  }
  
  if(root->data == x)
  {
    mark[level]=root->data;
    root->data=mark[nextPos];
    nextPos++;
    return root;
  }
  
  Node* left=reverse(root,mark,x,nextPos,level+1);
  Node* right;
  if(left == NULL)
  {
    right=reverse(root,mark,x,nextPos,level+1);
  }
  
  if(left || right)
  {
    mark[level]=root->data;
    root->data=mark[nextPos];
    nextPos++;
    return root;
  }
  return NULL;
}
reversePath(Node* root,int x)
{
  map<int,int>mark;
  int nexePos=0;
  int level=0;
  reverse(root,mark,x,nextPos,level);
}
