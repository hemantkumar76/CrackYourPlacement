void  findFandS(Node *root,int count,int &cnt,int &f,int &s){
      
    if(root==NULL) return;
    
    findFandS(root->left,count,cnt,f,s);
    
    if(cnt==count/2-1){
        f=root->data;
    }
    
    if(cnt==count/2){
        s=root->data;
    }
   
     cnt++;
    
    
    findFandS(root->right,count,cnt,f,s); 
    
    
}
void countElemnts(Node *root,int &count){
    
     if(root==NULL) return;
     count++;
     countElemnts(root->left,count);
     countElemnts(root->right,count);
     return;
}
float findMedian(struct Node *root)
{
      int count=0;
      countElemnts(root,count);
      int f=0;
      int s=0;
      int cnt=0;
      findFandS(root,count,cnt,f,s);
      if(count%2!=0)
      return s*1.0;
      
      return (f+s)*1.0/2*1.0;
}
