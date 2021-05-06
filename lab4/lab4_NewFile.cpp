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
  for(int i = 0; i <= n1; i++) data[i] = d1[i];
  for(int i = 0; i <= n2; i++) data[i + n1] = d2[i];
  for(int i = 0; i <= n3_size; i++) data[i + n1 + n2] = d3_size[i];
  for(int i = 0; i <= n3; i++) data[i + n1 + n2 + n3_size] = d3[i];
  for(int i = 0; i <= n4_size; i++) data[i + n1 + n2 + n3_size + n3] = d4_size[i];
  for(int i = 0; i <= n4; i++) data[i + n1 + n2 + n3_size + n3 + n4_size] = d4[i];
}
void PrintBinaryFile(char* data, int n)
{
  fstream f_out("file.dat", ios::app | ios::binary);
  f_out.write((char*) &n, sizeof(int));
  f_out.write(data, n);
  f_out.close();
}
int main()
{
  char* data;
  int n = 0;
  cup A[3] =
  {
    {100, 2020, "Big", "Flower"},
    {80, 2021, "Big", "None"},
    {50, 2020, "Small", "Cat"}
  };
  for(int i = 0; i < 3; i++)
  {
    GetSeria(data, n, A[i]);
    PrintBinaryFile(data, n);
    delete[] data;
  }
}
