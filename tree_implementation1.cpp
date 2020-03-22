#include<bits/stdc++.h>
using namespace std;

class node
{
    public:

        int data;
        node*left;
        node*right;
        node(int a)
        {
            data=a;
            left=NULL;
            right=NULL;
        }
};

//built tree function for commpetitive programming 

node* built_tree()
{
    int d;
    cin>>d;
    if (d==-1)
    {
        return NULL;
    }
    node*newnode;
    newnode=new node(d);
    newnode->left=built_tree();
    newnode->right=built_tree();
    return newnode;
}
node*insert_for_BST(node*start,int d)
{
    if (start==NULL)
    {
        node*newnode;
        newnode=new node(d);
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    else if (d<start->data)
    {
        start->left=insert_for_BST(start->left,d);
    }
    else
    {
        start->right=insert_for_BST(start->right,d);
    }
    
    
}

// To built binary search tree  
node*Binary_search_tree(node*&start)
{
    cout<<"To break the tree put input -1"<<endl;
    int d=1;
    
    while(1==1)
    {
        cin>>d;
        if (d==-1)
        {
            break;
        }
        start=insert_for_BST(start,d);
    }    
    return start;


}
void pre_order(node*start)
{
    
    if (start==NULL)
    {
        return ;
    }
    cout<<start->data<<" ";
    pre_order(start->left);
    pre_order(start->right);

}

void in_order(node*start)
{
    if (start==NULL)
    {
        return  ;
    }
    in_order(start->left);
    cout<<start->data<<" ";
    in_order(start->right);
}

void post_order(node*start)
{
    if (start==NULL)
    {
        return ;
    }
    post_order(start->left);
    post_order(start->right);
    cout<<start->data<<" ";
}
//use to calculate height of tree 
int height_tree(node*start)
{
    if (start==NULL)
    {
        return -1;
    }
    int left_height=height_tree(start->left);
    int right_height=height_tree(start->right);
    if (left_height>right_height)
    {
        return left_height+1;
    }
    else
    {
        return right_height+1;
    }
    
}
//use to print kth level of tree 


void printKlevel_without_queue(node*start,int k)
{
    if (start==NULL)
    {
        return ;
    }
    if (k==1)
    {
        cout<<start->data<<" ";
        return ;
    }
    printKlevel_without_queue(start->left,k-1);
    printKlevel_without_queue(start->right ,k-1);

    return;
}
//complexcity of code is n^2 which can be redused to O(n) using queue
void printAll_Level(node*start)
{
    int H=height_tree(start);
    for (int i=1 ;i<=H ;i++)
    {
        printKlevel_without_queue(start,i);
    }
}
//breath first traversal algo for tree in O(n) using queue;

void Level_order_using_queue(node*start)
{
    queue<node*>s;
    s.push(start);
    while(!s.emplace())
    {
        cout<<s.front()<<" ";
        s.pop();
        if (start->left!=NULL)
        {
            s.push(start->left);
        }
        if (start->right!=NULL)
        {
            s.push(start->right);
        }
    }
}



int main()
{
    node*start;
    start=NULL;
    //start=built_tree();
    start=Binary_search_tree(start );
    pre_order(start);
    cout<<endl;
    cout<<height_tree(start)<<endl;
    return 0;
}