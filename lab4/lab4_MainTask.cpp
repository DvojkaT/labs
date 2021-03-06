#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct cup
{
  int price;
  int date;
  string size;
  string picture;
};
struct MyQueue
{
  struct Node
  {
    char* data;
    int nnn;
    Node* next;
  };
  Node* First = NULL;
  int Count = 0;
  bool Push(char*, int n);
  bool Pop(char*&, int& n);
};
bool MyQueue::Push(char* data, int n)
{

  if(!First)
  {
    First = new Node;
    First -> next = NULL;
    First -> data = new char[n];
    for(int i = 0; i < n; i++) (First -> data)[i] = data[i];
    Count = 1;
    First -> nnn = n;
  }
  else
  {
    Node *temp;
    temp = First;
    while(temp -> next != NULL) temp = temp -> next;
    temp -> next = new Node;
    temp -> next -> data = new char[n];
    for(int i = 0; i < n; i++) (temp -> next -> data)[i] = data[i];
    temp -> next -> nnn = n;
    temp -> next -> next = NULL;
    Count++;
  }
  return true;
}
bool MyQueue::Pop(char*& data, int& n)
{
  if(!First) return false;
  Node* temp = First -> next;
  n = First -> nnn;
  data = new char[n];
  for(int i = 0; i < First -> nnn; i++) data[i] = (First -> data)[i];
  delete[] (First -> data);
  delete First;
  First = temp;
  Count--;
  return true;
}
void GetSeria(char*& data, int &n, cup A)
{
  size_t s1 = A.size.size();
  size_t s2 = A.picture.size();
  int n1 = sizeof(int);
  int n2 = sizeof(int);
  int n3_size = sizeof(size_t);
  int n3 = s1;
  int n4_size = sizeof(size_t);
  int n4 = s2;
  n = n1 + n2 + n3_size + n3 + n4_size + n4;
  data = new char [n];
  char* d1 = reinterpret_cast<char*> (&A.price);
  char* d2 = reinterpret_cast<char*> (&A.date);
  char* d3_size = reinterpret_cast<char*> (&s1);
  char* d3 = const_cast<char*> (A.size.c_str());
  char* d4_size = reinterpret_cast<char*> (&s2);
  char* d4 = const_cast<char*> (A.picture.c_str());
  for(int i = 0; i < n1; i++) data[i] = d1[i];
  for(int i = 0; i < n2; i++) data[i + n1] = d2[i];
  for(int i = 0; i < n3_size; i++) data[i + n1 + n2] = d3_size[i];
  for(int i = 0; i < n3; i++) data[i + n1 + n2 + n3_size] = d3[i];
  for(int i = 0; i < n4_size; i++) data[i + n1 + n2 + n3_size + n3] = d4_size[i];
  for(int i = 0; i < n4; i++) data[i + n1 + n2 + n3_size + n3 + n4_size] = d4[i];
}
void GetDeSeria(char* data, int n, cup& A)
{
  int n1, n2, n3_size, n3, n4_size, n4;
  n1 = sizeof(int);
  n2 = sizeof(int);
  n3_size = sizeof(size_t);
  size_t p1 = *reinterpret_cast<size_t*> (data + n1 + n2);
  n3 = p1;
  string s1(data + n1 + n2 + n3_size, p1);
  n4_size = sizeof(size_t);
  size_t p2 = *reinterpret_cast<size_t*> (data + n1 + n2 + n3_size + n3);
  n4 = p2;
  string s2(data + n1 + n2 + n3_size + n3 + n4_size, p2);
  A.price = *reinterpret_cast<int*> (data);
  A.date = *reinterpret_cast<int*> (data + n1);
  A.size = s1;
  A.picture = s2;
}
bool InputBinaryFile(MyQueue &Q)
{
  fstream file("file.dat", ios::in | ios::binary);
  if(!file)
  {
    return false;
  }
  cup A;
  int n = 0;
  while(!file.eof())
  {
    if(file.read((char*) &n, sizeof(int)))
    {
      char* data = new char[n];
      file.read(data, n);
      GetDeSeria(data, n, A);
      delete[] data;
      GetSeria(data, n, A);
      Q.Push(data, n);
    }
  }
  file.close();
  return true;
}
int main()
{
  MyQueue Q;
  char* data;
  int n = 0;
  int m = 1;
  cup A;
  InputBinaryFile(Q);
  while(m)
  {
    cout << "1. New cup" << endl;
    cout << "2. Pull cup" << endl;
    cout << "3. Clear" << endl;
    cout << "0. Exit" << endl;
    cin >> m;
    switch(m)
    {
      case 1:
      {
        cout << "Enter new cup:" << endl;
        cout << "Price = "; cin >> A.price;
        cout << "Date = "; cin >> A.date;
        cout << "Size = "; cin >> A.size;
        cout << "Picture = "; cin >> A.picture;
        GetSeria(data, n, A);
        Q.Push(data, n);
        break;
      }
      case 2:
      {
        cup A_x;
        bool metka = false;
        cout << "Enter cup:" << endl;
        cout << "Price = "; cin >> A_x.price;
        cout << "Date = "; cin >> A_x.date;
        cout << "Size = "; cin >> A_x.size;
        cout << "Picture = "; cin >> A_x.picture;
        int Y = Q.Count;
        for(int i = 0; i < Y; i++)
        {
          Q.Pop(data, n);
          GetDeSeria(data, n, A);
          delete[] data;
          if(A.price != A_x.price|| A.date != A_x.date || A.size != A_x.size || A.picture != A_x.picture)
          {
            GetSeria(data, n, A);
            Q.Push(data, n);
            delete[] data;
          }
          else
          {
            metka = true;
            break;
          }
        }
        if(!metka) cout << "Product not found" << endl;
        break;
      }
      case 3:
      {
        while(Q.Count)
        {
          Q.Pop(data, n);
          GetDeSeria(data, n, A);
          delete[] data;
          cout << "Price = " << A.price << endl;
          cout << "Date = " << A.date << endl;
          cout << "Size = " << A.size << endl;
          cout << "Picture = " << A.picture << endl << endl;
        }
        break;
      }
    }
  }
while(Q.Count)
{
  Q.Pop(data, n);
  delete[] data;
}
}