#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node(int d){
		data = d;
	}
};
stack <node*> checkroot;
stack <bool> direction;
queue <node*> print;
node* insrt(){
	int d;
	cout<<"node value: ";
	cin>>d;
	if(d!=0){
		node *root=new node(d);
		cout<<"left child of "<<d;
		root->left = insrt();
		cout<<"right child of "<<d;
		root->right = insrt();
		return root;
	}
	return NULL;
}

void traversal(node *root){
	print.push(root);
	node *p;
	while(print.size()!=0){
		p=print.front();
		print.pop();
		cout<<p->data<<" ";
		if(p->left!=NULL) print.push(p->left);
		if(p->right!=NULL) print.push(p->right);
	}
}

void post_traversal(node * root){
	node *p=root,*cur;
	while(p->left!=NULL){
		checkroot.push(p);
		p=p->left;
	}
	while(true){
		if(p->right==NULL||p->right==cur){
			cout<<p->data<<" ";
			cur=p;
			if(checkroot.empty()) break;
			p=checkroot.top();
			checkroot.pop();
		}
		else{
			checkroot.push(p);
			p=p->right;
			while(p->left!=NULL){
				checkroot.push(p);
				p=p->left;
			}
		}
	}
}

int main(){
	node *root = insrt();
	traversal(root);
	cout<<endl;
	post_traversal(root);
}
