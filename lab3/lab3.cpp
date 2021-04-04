#include <iostream>
using namespace std;

struct Laptop{
    string color;
    int Price;
};
struct Stack{
struct Node{
    Laptop data;
    Node* next;
};
    Node *F=NULL;//Первый эл сп
    Node *C=NULL;//Тек эл сп
    int Count=0;//Длина списка
    bool CreateList(Laptop lap);
    bool AddNext(Laptop lap);
    bool Print();
    void NewLaptop(Stack st,Laptop lap, char *color, int Price);
    bool Del(Laptop& lap);
};

void read(Stack&,char*);

int main(){
    Stack first;
    Stack second;
    Laptop lap;
int choice;

        cout<<"-------Menu-------"<<endl;
        cout<<"1. Show top laptop"<<endl;
        cout<<"2. Add new laptop"<<endl;
        cout<<"0. Exit"<<endl;
        do{
        cout<<"Choose option: "; 
        cin>>choice;
        switch(choice){
            case 1:{
                first.Print();
                break;
            }
            case 2:{
                cout<<"Write price: ";cin>>lap.Price;
                cout<<"Write color: ";cin>>lap.color;
                first.AddNext(lap);
                break;
            case 3:{
                first.Del(lap);
                break;
            }
            }
        }
    }while(choice!=0);
}

bool Stack::CreateList(Laptop lap){
    F=new Node;
    F->next=NULL;
    F->data=lap;
    C=F;
    Count++;
    return true;
}

bool Stack::AddNext(Laptop lap){
    if(F==NULL) return Stack::CreateList(lap);
    Node *temp;
    temp = new Node;
    temp->next=F ;
    F=temp;
    F->data=lap;
    Count++;
    return true;
}

bool Stack::Print(){
    if(F==NULL) cout<<endl<<"---List is empty---"<<endl;
    else {cout<<endl<<"Top model:\t"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Price: "<<F->data.Price<<endl;
        cout<<"Color: "<<F->data.color<<endl;
        cout<<"---------------------------------"<<endl;
    cout<<endl<<"Count = "<<Count<<endl;
    }
    return true;
}



bool Stack::Del(Laptop& data){ 
  if(!F) return false;
  Node *temp = F -> next;
  data = F -> data;
  delete F;
  F = temp;
  Count--;
  return true;
}

void read(Stack&,char*){


}
