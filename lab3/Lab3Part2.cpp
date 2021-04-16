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
    int AllPrice = 0;
    int full = 0;
    bool Push(consignment);
    bool Pop(consignment&);
    void Info();
    void deletion(consignment&);
};
bool MyQueue::Push(consignment data)
{
    if (!First)
    {
        First = new Node;
        First->next = NULL;
        First->data = data;
        Count = 1;
        AllPrice += data.Price * data.Amount;
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
        AllPrice += data.Price * data.Amount;
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
void MyQueue::deletion(consignment& k){
    while (Count !=0) Pop(k);
}
 
void menu(MyQueue q);
bool check(MyQueue q, consignment second){
    consignment first;
    MyQueue::Node *a;
    a=q.First;
    int k=0;
    while(a->data.Price<=second.Price && k!=q.Count)
    {
        first.Price = a->data.Price;
        first.Amount = a->data.Amount;
        if(second.Amount<=first.Amount)
        {
            second.Amount = 0;
        }
        else{
            second.Amount -= first.Amount;
        }
        if(second.Amount==0) return true;
        else{
            if(k<q.Count){
                k++;
                a=a->next;
            }
            else return false;
        }
    }
    return false;
}
 
int main()
{
    consignment a;
    MyQueue Q;
    menu(Q);
    Q.deletion(a);
}
 
void menu(MyQueue q) {
    consignment first;
    consignment second;
    int k,am;
    do {
        cout << "1.Add new product" << endl;
        cout << "2.Sell product" << endl;
        cout << "3.Report" << endl;
        cout << "0.Exit" << endl;
        cin >> k;
        switch (k) {
        case 1:
            cout << "Enter Price: "; cin >> second.Price;
            cout << "Enter amount: "; cin >> second.Amount;
            q.Push(second);
            q.full+=second.Amount;
            break;
        case 2:
        cout<<"Enter price: ";cin>>second.Price;
        cout<<"Enter amount: ";cin>>second.Amount;
        first = q.First->data;
        if(check(q, second)){
        while(second.Amount){
            if(second.Amount<=first.Amount){
                q.payment += second.Amount * (second.Price - first.Price);
                q.AllPrice -= first.Price * second.Price;
                first.Amount -= second.Amount;
                q.full -= second.Amount;
                second.Amount = 0;
                q.First->data.Amount= first.Amount;
            }
            else{
                q.payment += first.Amount * (second.Price - first.Price);
                q.AllPrice -= first.Price * first.Amount;
                second.Amount -= first.Amount;
                q.full -=(second.Amount -= first.Amount);
                first.Amount = 0;
                q.First->data.Amount=first.Amount;
            }
            if (first.Amount==0){
                q.Pop(first);
                first = q.First ->data;
            }
        }
            cout<<"Purchase complete"<<endl;
        }
        else cout<<"Purchase failed"<<endl;
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