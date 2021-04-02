#include <iostream>
#include <fstream>
using namespace std;

struct crocodile{
    int age;
    string color;
    void out();
    bool IsEqual(crocodile);
};

struct MyStack
{
  struct Node
  {
    crocodile data;
    Node *prev;
  };
  Node *Top = NULL;
  int Count;
  bool Push(crocodile);
  bool Pop(crocodile&);
  void Info();
};

void crocodile::out(){
    cout<<"age: "<<age<<" color: "<<color<<endl;
}

bool crocodile::IsEqual(crocodile a){
    if(a.age==age&&a.color==color) return true;
    return false;
}

bool MyStack::Push(crocodile data)
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
bool MyStack::Pop(crocodile &data)
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
    cout << endl << "Stack info: " << endl;
    cout << "\tStack size = " << Count << endl;
    //cout <<"\tTop data = " << Top -> data << endl << endl;
    Top->data.out();
  }
}


void read(MyStack&,char*);
void FindCr(MyStack&);

int main()
{
  int n = 10; crocodile k;
  crocodile a={10,"brown"},b={5,"green"};
  MyStack S;
  S.Info();
    read(S,"text.txt");
  S.Info();
  FindCr(S);
  S.Info();
  while(S.Pop(k))
    k.out();
  cout << endl;
  S.Info();
}

void read(MyStack& S,char* FileName){
ifstream F(FileName);
if (!F){ cout<<"Error";
return;
}
crocodile cr;
while(F>>cr.age>>cr.color) S.Push(cr);
F.close();
}

void FindCr(MyStack& S){
    crocodile find={10,"black"}, cr;
    MyStack second;
    while(S.Count != 0&&!(S.Top->data.IsEqual(find))){
        S.Pop(cr);
        second.Push(cr);
    }
    if(S.Count!=0){
        cout<<"Crocodile is found"<<endl;
        S.Pop(cr);
    }
    else cout<<"Crocodile is not found"<<endl;
    while(second.Pop(cr)) S.Push(cr);
}