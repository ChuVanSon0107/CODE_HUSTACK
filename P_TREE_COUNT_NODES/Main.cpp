#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* firstChild;
    struct node* sibling;
};

struct node* makeNode(int data){
    struct node* newNode = new struct node();
    newNode -> data = data;
    newNode -> firstChild = NULL;
    newNode -> sibling = NULL;
    return newNode;
}

struct node* find(struct node* root, int v){

    if(root == NULL) return NULL;

    if(root -> data == v){
        return root;
    }

    struct node* curr = root -> firstChild;
    struct node* temp = NULL;

    while(curr != NULL){
        temp = find(curr, v);
        if(temp != NULL){
            return temp;
        }
        
        curr = curr -> sibling;
    }

    return NULL;
}

void insert(struct node** root, int u, int v){
    struct node* parent = find((*root), v);
    struct node* node = parent -> firstChild;

    if(node == NULL){
        parent -> firstChild = makeNode(u);
        return;
    }

    while(node -> sibling != NULL){
        node = node -> sibling;
    }

    node -> sibling = makeNode(u);
    return;
}

void countLeaves(struct node* curr, int* cnt){
    if(curr == NULL){
        return;
    }

    if(curr -> firstChild == NULL){
        (*cnt) ++;
        return;
    }

    curr = curr -> firstChild;
    
    while(curr != NULL){
        countLeaves(curr, cnt);
        curr = curr -> sibling;
    }
    return;
}

void countKChildren(struct node* curr, int k, int* cnt){
    
    if(curr == NULL) return;
    if(curr -> firstChild == NULL) return;

    curr = curr -> firstChild;
    int countChildren = 1;
    while(curr != NULL){
        countKChildren(curr, k, cnt);

        if(curr -> sibling != NULL){
            countChildren ++;
        }
        curr = curr -> sibling;
    }

    if(countChildren == k){
        (*cnt) ++;
    } 

    return;
}

int main(){
    struct node* root = NULL;
    string s;
    string tmp;
    string a[3];
    int i = 0;
    while(true){
        getline(cin, s);
        if(s == "*") break;
        else{
            stringstream ss(s);
            i = 0;
            while(ss >> tmp){
                a[i] = tmp;
                i ++;
            }

            if(a[0] == "MakeRoot"){
                root = makeNode(stoi(a[1]));
            }
            else if(a[0] == "Insert"){
                insert(&root, stoi(a[1]), stoi(a[2]));
            }
            else if(a[0] == "CountLeaves"){
                int cnt = 0;
                countLeaves(find(root, stoi(a[1])), &cnt);
                cout << cnt << endl;
            }
            else if(a[0] == "CountKChildren"){
                int cnt = 0;
                countKChildren(find(root, stoi(a[1])), stoi(a[2]), &cnt);
                cout << cnt << endl;
            }
        }

    };

    return 0;
}