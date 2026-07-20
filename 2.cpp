// ENCAPSULATION

#include <iostream>
using namespace std;
class Employees{
    private:
        int acc_no;
        int IFS;
        string name;
        bool saving;
        double *acc_bal;
        double *debt;

    public:
    //================Default Constructor===================
        Employees(){
            cout << "Employees constructor was called: " << endl;
            acc_no = 0;
            IFS = 0;
            name = "unknown";
            saving = 0;
            acc_bal = new double(0.0);
            debt = new double(0.0);
        }
        //Paramaterised constructor
        Employees(int acc_no, int IFS, string name, bool saving,
                  double bal = 0.0, double debt_amt = 0.0){
            cout << "Employees parameterised constructor called"<< endl;
            this -> acc_no = acc_no;
            this -> IFS = IFS;
            this -> name = name;
            this -> saving = saving;
            acc_bal = new double(bal);
            debt = new double(debt_amt); 
        }

        // ====================GETTER============================
        int getAccNo()const{
            return acc_no;
        }
        int getIFS()const{
            return IFS;
        }
        string getName()const{
            return name;
        }
        bool isSaving()const{
            return saving;
        }
        double getBalance()const{
            return *acc_bal;
        }
        double getDebt()const{
            return *debt;
        }
        //======================SETTER======================
        void setAccNo(int accNo){
            this -> acc_no = accNo;
        }
        void setIFS(int IFS){
            this -> IFS = IFS;
        }
        void setName(const string &name){
            this -> name = name;
        }
        void setSaving(bool sav){
            this -> saving = sav;
        }
        void setBalance(double bal){
            if(bal < 0){
                cout << "Balance can not be zero"<< endl;
                return;
            }
            *acc_bal = bal;
        }
        void setDebt(double debt_amt){
            if(debt_amt < 0){
                cout << "Debt can not be zero"<< endl;
                return;
            }
            *debt = debt_amt;
        }
        //===================BEHAVIOUR METHOD=====================
        void Deposite(double amount){
            if(amount <= 0){
                cout << "Invalid deposite amount" << endl;
                return;
            }
            *acc_bal += amount;
        }
        void Withdraw(double amount){
            if(amount <= 0 || amount > *acc_bal){
                cout << "Invalid Teansection" << endl;
                return;
            }
            *acc_bal -= amount;
        }
        //=================Distructor =================
        ~Employees(){
            cout << "The default destructor is called for : " << name << endl;
            delete acc_bal;
            delete debt;
        }
   

};
int main(){
    
    Employees A;
    cout << "A's Balance " << A.getBalance() << " A's debt " << A.getDebt()<< endl;
    A.setAccNo(75747);
    A.Deposite(7653.66);
    cout << "A's Account no: " << A.getAccNo() << "  A's Balance : " << A.getBalance() << endl;
    Employees B(101, 449, "Rudra", true, 5345.65, 788.00);
    cout << "B's Balance " << B.getBalance() << " B's debt " << B.getDebt()<< endl;
    B.Deposite(475.99);
    cout << "B's Balance : " << B.getBalance() << endl;
    A.setName("Pawan");
    cout << A.getName() << "  " << B.getName() << endl;
    return 0;
}