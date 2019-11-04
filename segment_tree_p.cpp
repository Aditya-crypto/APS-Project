#include<bits/stdc++.h>
using namespace std;
int size;
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
struct node* newnode(int val)
{
     struct node* np=new node();
     np->data=val;
     np->left=NULL;
     np->right=NULL;
     return np;
}
struct node* build_tree(vector<int>& v,int& i,int srt,int end)
{
     if(srt==end)
     {
       // cout<<srt<<" "<<end<<"\n";
        struct node* root=newnode(v[i++]);
        return root;
     }
     int mid=srt+(end-srt)/2;
     struct node* root=newnode(INT_MAX);
     root->left=build_tree(v,i,srt,mid);
     root->right=build_tree(v,i,mid+1,end);
     root->data=min(root->left->data,root->right->data);
     
     return root;
}
int range_query(struct node* root,int qs,int qe,int srt,int end)
{    
     
     if(end<qs || srt>qe)
     return INT_MAX;
     else if(srt>=qs && end<=qe)
     return root->data;
     else
     {
        int mid=srt+(end-srt)/2;
        return min(range_query(root->left,qs,qe,srt,mid),
        range_query(root->right,qs,qe,mid+1,end));
        
     }
}
void inorder(struct node* root)
{
     if(!root)
     return;
     else
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
struct node* upgrade(struct node* v1,struct node* v2,int index,int val,int srt,int end)
{
     struct node* prev=v1;
     struct node* temp=newnode(INT_MAX);
     v2=temp;
     int mid=srt+(end-srt)/2;
     if(srt==end)
     {
          temp->data=val;
          return temp;
     }
     if(index<=mid)
       {
          temp->right=prev->right;
          prev=prev->left;
          temp->left=upgrade(prev,temp,index,val,srt,mid);
          temp->data=min(temp->right->data,temp->left->data);
       }
     else
       {
           temp->left=prev->left;
           prev=prev->right;
           temp->right=upgrade(prev,temp,index,val,mid+1,end);
           temp->data=min(temp->right->data,temp->left->data);
       }
       return temp;
     
}
int main()
{
     int n;
     cin>>n;
     size=n;
     vector<int> v(n);
     for(int i=0;i<n;i++)
     {
        cin>>v[i];
     }
     int pos=0;
     struct node* root=build_tree(v,pos,0,n-1);
     vector<struct node*> version(10);
     version[0]=root;
     inorder(root);
     cout<<"\n";
     cout<<range_query(root,1,2,0,n-1)<<" \n";
     
     version[1]=upgrade(version[0],version[1],2,-1,0,n-1);
     inorder(version[1]);
     cout<<"\n";
      cout<<range_query(version[1],1,2,0,n-1)<<" \n";
     cout<<"\n";
}
