#include <iostream>
using namespace std;

class Student{
    private:
        string name;
        int roll_no;
        int age;
        int _class;
        bool GF;
    
    public:

        Student(){
            cout << " Student constructor is called:" << endl;
            name = "Sarthak";
            roll_no = 25;
            age = 16;
            _class= 7;
            GF = 0; 
        }

        Student (string name, int roll_no, int age, int _class, bool GF){
            cout << "Paramaterisec constructor is callled:" << endl;
            this -> name = name;
            this -> roll_no = roll_no;
            this -> age = age;
            this -> _class = _class;
            this -> GF = GF;
        }

        //=================GETTER=========================

        string getname() const{
            return name;
        }

        int getroll_no() const{
            return roll_no;
        }
        int  getage() const{
            return age;
        }
        int get_class() const{
            return _class;
        }
        bool getGF(){
            return GF;
        }
        //===============SETTER==============================

        void setname(string name){
            this -> name = name;
        }
        void setroll_no(int roll){
            if(roll <= 0) cout << "Invalid ROll no:" << endl; return ;
            this -> roll_no = roll;
        }
        void setage(int age){
            if(age <= 0) cout << "Invalid age:" << endl; return ;
            this -> age = age;
        }
        void set_class(int _class){
            if(_class <= 0 || _class > 12) cout << "Invalid class:" << endl; return ;
            this -> _class = _class;
        }

        void setGF (bool _GF){
            this -> GF = _GF;
        }
};

int main(){
    Student Aryan;
    Aryan.setname("Aryan");
    Aryan.set_class(9);
    Aryan.setGF(1);

    cout << " THE Student name is : " << Aryan.getname() << " and his age is : "
    << Aryan.getage() << " \n and he has " <<  ( Aryan.getGF() == 0 ? "NO" :  " ") << " GF" << endl;
    return 0;
}
