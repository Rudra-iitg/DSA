#include <iostream>
using namespace std;

class recursion{
    public:
    int write_sum(int n){
        if(n <= 0){
            return 0;
        }
        return n += write_sum(n-1);
    }
};

int main(){
    cout << "Enter an number: ";
    int n;
    cin >> n;
    cout << "The numbers are: " ;
    recursion re;
    cout << re.write_sum(n) << '\n';
    return 0;
}