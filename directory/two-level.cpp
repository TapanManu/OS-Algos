# include <iostream>
# include <bits/stdc++.h>

using namespace std;

struct node {
    char data[25];
    int tag;
    node* dir;
    node* next;
} *head,*ptrf,*ptr,*p;

node* createnode(char* data,int tag){
    p = new node;
    strcpy(p->data,data);
    p->next = NULL;
    p->dir = NULL;
    p->tag = tag;
    return p;
}

void traverse(){
    ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"\n";
        ptrf = ptr->next;
       
        while(ptrf!=NULL){
            cout<<ptrf->data<<"\t";
            ptrf = ptrf->next;
        }
        ptr = ptr->dir;
        cout<<"\n\n";
    }
}

void insert(char* data){
    node* ptr = head;
    char f[25];
    int found=0;
    while(ptr != NULL){
        if(!strcmp(data,ptr->data)){
            node* file = ptr->next;
            node* prev;
            while(file!=NULL){
                prev = file;
                file = file->next;
            }
            found = 1;
            cout<<"enter file name\n";
            cin>>f;
            node* t = createnode(f,0);
            prev->next = t;
        }
    ptr = ptr->dir;
    }
    if(found==0){
        cout<<"directory not found\n";
    }
}

int main(){
    node *d = head;
    char ch='y',ch1='y';
    char data[25];
    while(ch!='n'){
        cout<<"enter directory data\n";
        cin>>data;
        node* tmpdir = createnode(data,1);
        
        if(head==NULL){
            head = tmpdir;
            d = head;
        }
        else{
            d->dir = tmpdir;
            d = tmpdir;
        }
        cout<<"do you want to insert files into it?(y/n)";
        cin>>ch1;
        node* f = d->next;
        while(ch1!='n'){
            cout<<"enter data\n";
            cin>>data;
            node* tmp = createnode(data,0);
            if(d->next==NULL){
                d->next = tmp;
                f = d->next;
            }
            else{
                f->next = tmp;
                f = tmp;
            }
            cout<<"do you want to insert more files(y/n)?";
            cin>>ch1;
        }
        cout<<"do you want to insert more directory(y/n)?";
        cin>>ch;
    }
    char ins[25];
    char c='y';
    int choice;
    while(c!='n'){
        cout<<"1.Insert Files\n";
        cout<<"2.Traverse\n";
        cout<<"press any key to EXIT\n";
        cout<<"Please select";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"specify directory name to be inserted";
                cin>>ins;
                insert(ins);
                break;
            case 2:
                traverse();
                break;
            default:
                exit(0);
        }
    }

    traverse();
    return 0;
}
