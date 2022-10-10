void postorder(int pre[],int n,int minval,int maxval,int pi)
{
  if(pi == n)
  {
    return;
  }
  
  if(pre[preIndex] < minval || pre[preIndex] > maxval) 
  {
       return;
  }
  
  int val=pre[pi];
  pi++;
  
  postorder(pre,n,minval,val,pi);
  postorder(pre,n,val,maxval,pi);
  
  cout<<val<<" ";
}
void findPostOrder(int pre[],int n)
{
  int preIndex=0;
  postorder(pre,n,INT_MIN,INT_MAX,preIndex);
}
int main()
{
  int pre[] = { 40, 30, 35, 80, 100 };
  int n = sizeof(pre) / sizeof(pre[0]);
  
  findPostOrder(pre,n);
}
