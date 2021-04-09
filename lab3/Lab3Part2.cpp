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
    int MinPrice = 0;
    int full = 0;
    bool Push(consignment);
    bool Pop(consignment&);
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
        MinPrice=First->data.Price;
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
        if (MinPrice<First->data.Price) MinPrice=First->data.Price;
    }
    return true;
}
bool MyQueue::Pop(consignment& data)
{
    if (!First) return false;
    Node* temp = First->next;
    data = First->data;
    delete First;
    First = temp;
    Count--;
    return true;
}
void MyQueue::Info()
{
    if (!First) cout << "Queue is empty" << endl;
    else
    {
        cout << endl << "Queue info: " << endl;
        cout << "\tQueue size = " << Count << endl;
        First->data.out();
    }
}
 
void menu(MyQueue q);
 
int main()
{
    int n = 10;
    double db=0;
    MyQueue Q;
    menu(Q);
    return 0;
 
}
 
void menu(MyQueue q) {
    consignment Ctop;
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
            q.full+=am;
            break;
        case 2:
        cout<<"Enter price: ";cin>>pr;
        cout<<"Enter amount: ";cin>>am;
        while(am!=0){
            if(q.MinPrice>pr){
                cout<<"WARNING--Too cheap--WARNING"<<endl;
                break;
            }
            if(am<q.First->data.Amount&&q.First->data.Price<=pr){
                q.First->data.Amount-=am;
                q.payment += am * (pr - q.First->data.Price);
                q.full -= am;
                am=0;
            }
            if(q.full<am){
                cout<<"WARNING--AMOUNT IS TOO BIG--WARNING"<<endl;
                break;
            }
            else{
                am-=q.First->data.Amount;
                q.payment += q.First->data.Amount * (pr - q.First->data.Price);
                q.full -= q.First->data.Amount;
                q.First->data.Amount=0;
            }
            if (q.First->data.Amount==0){
                q.Pop(a);
                q.MinPrice=q.First->data.Price;
            }
        }
            break;
        case 3:
            q.Info();
            cout << "Payment: " << q.payment << endl;
            cout << "Full: " << q.full << endl;;
            break;
        case 4:
            break;
        }
    } while (k != 0);
}