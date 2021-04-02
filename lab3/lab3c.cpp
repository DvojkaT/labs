#include <iostream>
using namespace std;
 
 
struct consignment {
    double Price;
    int Amount;
    void out();
};
 
void consignment::out() {
    cout << "Price: " << Price << " " << "Amount: " << Amount<<endl;
}
 
struct MyQueue
{
    struct Node
    {
        consignment data;
        Node* next;
    };
    Node* First = NULL;
    int Count = 0;
    int payment = 0;
    int full = 0;
    bool Push(consignment);
    bool Pop(consignment&,double);
    void Info();
};
bool MyQueue::Push(consignment data)
{
    if (!First)
    {
        First = new Node;
        First->next = NULL;
        First->data = data;
        Count = 1;
        full = First->data.Amount;
    }
    else
    {
        Node* temp;
        temp = First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node;
        temp->next->data = data;
        temp->next->next = NULL;
        Count++;
        full += temp->data.Amount;
    }
    return true;
}
bool MyQueue::Pop(consignment& data, double Price)
{
    if (!First) return false;
    Node* temp = First->next;
    data = First->data;
    delete First;
    First = temp;
    Count--;
    full -= First->data.Amount;
    payment += First->data.Amount * (First->data.Price - Price);
    return true;
}
void MyQueue::Info()
{
    if (!First) cout << "Queue is empty" << endl;
    else
    {
        cout << endl << "Queue info: " << endl;
        cout << "\tQueue size = " << Count << endl;
        //cout << "\tFirst data = " << First->data << endl << endl;
        First->data.out();
    }
}
 
void menu(MyQueue q);
 
int main()
{
    int n = 10;
    double db=0;
    consignment k, k1 = { 12.2,5 }, k2 = {5.43,2};
    MyQueue Q;
    Q.Info();
    //for (int i = 1; i <= n; i++) Q.Push(i);
    Q.Push(k1);
    Q.Push(k2);
    menu(Q);
    //Q.Info();
    while (Q.Pop(k,db)) k.out();
    cout << endl;
    Q.Info();
    return 0;
 
}
 
void menu(MyQueue q) {
    consignment a;
    double pr;
    int k,am;
    do {
        cout << "1.Add new product" << endl;
        cout << "2.Sell product" << endl;
        cout << "3.Report" << endl;
        cout << "0.Exit" << endl;
        cin >> k;
        switch (k) {
        case 1:
            cout << "Enter Price: "; cin >> pr;
            cout << "Enter amount: "; cin >> am;
            a.Price = pr;
            a.Amount = am;
            q.Push(a);
            break;
        case 2:
            break;
        case 3:
            cout << "Payment: " << q.payment << endl;
            cout << "Full: " << q.full << endl;;
            break;
        case 4:
            break;
        }
    } while (k != 0);
}