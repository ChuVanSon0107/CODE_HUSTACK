#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node * next;
};

bool existNode(struct node* head, int k){
    struct node* temp = head;
    while(temp != NULL){
        if(temp->data == k){
            return true;
        }
        temp = temp -> next;
    }

    return false;
}

struct node* createNode(int k){
    struct node* newNode = new struct node();
    newNode->data = k;
    newNode->next = NULL;
    return newNode;
}

void addFirst(struct node** head, int k){
    struct node* temp = *head;
    if(existNode(temp, k) == false){
        struct node* newNode = createNode(k);
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }
}

void addLast(struct node** head, int k){
    struct node* temp = *head;
    if(existNode(temp, k) == false){
        bool exist = false;
        struct node* temp = (*head);
        if(temp == NULL){
            (*head) = createNode(k);
            return;
        }

        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = createNode(k);
            return;
        }
    }
}

void addBefore(struct node** head, int u, int v){
    struct node* temp = *head;
    if(existNode(temp, u) == false){
        if((*head)->data == v){
            addFirst(head, u);
            return;
        }
        else{
            struct node* temp = *head;
            while((temp->next)->data != v){
                temp = temp->next;
            }

            if(temp != NULL){
                struct node* newNode = createNode(u);
                newNode->next = temp->next;
                temp->next = newNode;
            }
            return;
        }
    }
}

void addAfter(struct node** head, int u, int v){
    struct node* temp = *head;
    if(existNode(temp, u) == false){
        while(temp->data != v){
            temp = temp->next;
        }

        if(temp != NULL){
            struct node* newNode = createNode(u);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        return;
    }
}

void remove(struct node** head, int k){
    if(existNode(*head, k) == true){
        struct node* temp = *head;
        if((*head)->data == k){
            (*head) = (*head)->next;
            free(temp);
        }
        else{
            while(temp->next->data != k){
                temp = temp->next;
            }
                    struct node* t = temp->next;
            temp->next = t->next;
            free(t);

        }
    }
}

void reverse(struct node** head){
    struct node* prev = NULL;
    struct node* curr = (*head);
    struct node* next = (*head)->next;
    if(next == NULL) return;
    while(next != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }

    curr->next = prev;
    *head = curr;
}

void printLinkedList(struct node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    int n;
    cin >> n;
    struct node* head = NULL;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        addLast(&head, x);
    }

    string s;

    while(getline(cin, s)){
        if(s == "#") {
            printLinkedList(head);
            break;
        }
        stringstream ss(s);
        string word;
        string a[3];
        int i = 0;
        while(ss >> word){
            a[i] = word;
            i ++;
        }

        int u, v;

        if(a[0] == "addlast"){
            u = stoi(a[1]);
            addLast(&head, u);
        }

        else if(a[0] == "addfirst"){
            u = stoi(a[1]);
            addFirst(&head, u);
        }

        else if(a[0] == "addafter"){
            u = stoi(a[1]);
            v = stoi(a[2]);
            addAfter(&head, u, v);
        }
        else if(a[0] == "addbefore"){
            u = stoi(a[1]);
            v = stoi(a[2]);
            addBefore(&head, u, v);
        }
        else if(a[0] == "remove"){
            u = stoi(a[1]);
            remove(&head, u);
        }
        else if(a[0] == "reverse"){
            reverse(&head);
        }

    }

    return 0;
}