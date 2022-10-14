void hasDuplicate(Node* root,unordered_map<int,int>&map,bool &hasSame)
{
  if(root == NULL)
  {
    return;
  }
  
  hasDuplicate(root->left,map,hasSame);
  map[root->data]++;
  if(map[root->data] > 1)
  {
    hasSame=true;
  }
  hasDuplicate(root->right,map,hasSame);
}

bool ans(Node* root)
{
  unordered_map<int,int>map;
  bool hasSame;
  
  hasDuplicate(root,map,hasSame);
  return hasSame;
}
