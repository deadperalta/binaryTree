int findIndex(string s,int st,int en)
{
  stack<char>sta;
  
  for(int i=st;i<=en;i++)
  {
    if(s[i] == '(')
    {
      sta.push(s[i]);
    }
    else if(s[i] == ')')
    {
      if(sta.top() == '(')
      {
        sta.pop();
      }
      else if(sta.empty())
      {
        return i;
      }
    }
  }
  return -1;
}
Node* createTree(string s,int st,int en)
{
  if(st > en)
  {
    return NULL;
  }
  
  int num=0;
  
   while(si <= ei && str[st] >= '0' && str[st] <= '9')
   {
      num *= 10;
      num += (str[st] - '0');
      st++;
   }
   
  Node* root=new Node(num);
  ind=-1;
  if(st < en && s[st] == '(')
  {
    ind=findIndex(s,st,en);
  }
  
  if(ind != -1)
  {
    root->left=createTree(s,st,ind-1);
    root->right=createTree(s,ind+2,en);
  }
  return root;
}
