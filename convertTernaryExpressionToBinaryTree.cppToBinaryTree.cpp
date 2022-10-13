Node* convert(string s,int &i)
{
  Node* root=new Node(s[i]);
  
  if(i == s.size()-1)
  {
    return root;
  }
  i++;
  
  if(s[i] == '?')
  {
    i++;
    root->left=convert(s,i);
    
    i++;
    root->right=convert(s,i);
  }
  return root;
}

Node* convertExpressiomToBinary(string s)
{
  int i=0;
  return convert(s,i);
}
