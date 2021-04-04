#include <iostream>
#include <fstream>
using namespace std;

struct Laptop{
    int Price;
    string color;
    void out();
    bool IsEqual(Laptop);
};

struct MyStack
{
  struct Node
  {
    Laptop data;
    Node *prev;
  };
  Node *Top = NULL;
  int Count;
  bool Push(Laptop);
  bool Pop(Laptop&);
  void Info();
  void deletion(Laptop&);
};

void Laptop::out(){
    cout<<"Price: "<<Price<<" color: "<<color<<endl;
}

bool Laptop::IsEqual(Laptop a){
    if(a.Price==Price&&a.color==color) return true;
    return false;
}

bool MyStack::Push(Laptop data)
{
  if(!Top)
  {
    Top = new Node;
    Top -> prev = NULL;
    Count = 1;
  }
  else
  {
    Node *temp;
    temp = new Node;
    temp -> prev = Top;
    Top = temp;
    Count++;
  }
  Top -> data = data;
  return true;
}
bool MyStack::Pop(Laptop &data)
{
  if(!Top) return false;
  Node *temp = Top -> prev;
  data = Top -> data;
  delete Top;
  Top = temp;
  Count--;
  return true;
}
void MyStack::Info()
{
  if(!Top) cout << "Stack is empty" << endl;
  else
  {
    cout << endl << "\tStack info: " << endl;
    cout << "\tStack size = " << Count << endl;
    Top->data.out();
  }
}

void MyStack::deletion(Laptop& k){
  while (Count !=0) Pop(k);
}

void read(MyStack&,string);
void FindCr(MyStack&,Laptop);

int main()
{
  Laptop k;
  Laptop find;
  Laptop a={10,"brown"},b={5,"green"};
  MyStack S;
  char* color;
  int price;
  read(S,"text.txt");
  int choice;

        cout<<"-------Menu-------"<<endl;
        cout<<"1. Show top laptop"<<endl;
        cout<<"2. Add new laptop"<<endl;
        cout<<"3. Find laptop"<<endl;
        cout<<"4. Delete all"<<endl;
        cout<<"0. Exit"<<endl;
        do{
        cout<<"Choose option: "; 
        cin>>choice;
        switch(choice){
            case 1:{
                S.Info();
                break;
            }
            case 2:{
                cout<<"Write price: ";cin>>k.Price;
                cout<<"Write color: ";cin>>k.color;
                S.Push(k);
                break;
            case 3:{
              cout<<"Find:"<<endl;
              cout<<"Which price: ";cin>>find.Price;
              cout<<"Which color: ";cin>>find.color;
              FindCr(S,find);
              break;
            }
            case 4:{
                S.deletion(k);
                break;
            }
            }
        }
    }while(choice!=0);
}

void read(MyStack& S,string FileName){
ifstream F(FileName);
if (!F){ cout<<"Error";
return;
}
Laptop cr;
while(F>>cr.Price>>cr.color) S.Push(cr);
F.close();
}

void FindCr(MyStack& S,Laptop find){
    Laptop cr;
    MyStack second;
    while(S.Count != 0&&!(S.Top->data.IsEqual(find))){
        S.Pop(cr);
        second.Push(cr);
    }
    if(S.Count!=0){
        cout<<"Laptop is found"<<endl;
        S.Pop(cr);
    }
    else cout<<"Laptop is not found"<<endl;
    while(second.Pop(cr)) S.Push(cr);
}