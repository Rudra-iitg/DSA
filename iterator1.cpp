#include <iostream>
#include <vector>
#include <string>
#include <iterator> // Needed for task 4;
#include <set> // Needed for task 6;
using namespace std;
int main(){
    {
        vector<int> v = {4,64,43,7,23,64,7};
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
            if(*it > 10){
                cout << *it << "  ";
            }
        }
        cout << endl;
    }
    {
        vector<int> v = {3,5,7,13,65, 54, 33};
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
            *it *= 2;
            cout << *it << "  ";
        }
        cout << endl;
    }
    {
        vector<string> word = {"C++", "is" , "fun"};
        for(vector<string>::reverse_iterator it = word.rbegin(); it != word.rend(); ++it){
            cout << *it << "  ";
        } 
        cout << endl;
    }
    {   //This it += 2 or any num works only on vector or array, 
        vector<int> v = {4, 64,2,5,52,67,36,9,39,76,24,76,23,71,53,75};
        for(vector<int> ::iterator it = v.begin(); it != v.end(); it += 2){
            cout << *it << "  ";
        }
        cout << endl;
    }
    {
        vector<int> v = {4, 64,2,5,52,67,36,9,39,76,24,76,23,71,53,75};
        vector<int> ::iterator it = v.begin();
        advance(it, 2);
        cout << "Element : " << *it << endl;
        cout << *it << "  ";
        int steps = distance(it, v.end());
        cout << steps ;
        cout << endl; 
    }
    {
        vector<int> v = {1, 2, 3, 4, 5, 6};
        for(auto it = v.begin(); it != v.end(); ){
            if(*it % 2 == 0){
                it = v.erase(it);
            }
            else{
                ++it;
            }
        }
        for(int x : v){
            cout << x << "  ";
        }
        cout << endl;
    }
    {
        set<int> s = {10,20,30,40,50};
        set<int>::iterator it = s.lower_bound(25);
        if(it != s.end()){
            cout << "Found " << *it << endl;
            s.erase(it);
        }
        for(int x : s){
            cout << x << "  ";
        }
        cout << endl;
    }
    {
        vector<int> nums = {3,5,7,9,12,13,24,26,31,33,34,39,47,56};
        int target = 87;
        vector<int>::iterator left = nums.begin();
        auto right = nums.end() - 1;
        while(left < right){
            int sum = *left + *right ;
            if(sum == target){
                cout << "Found the elemtents: " << *left << " , " << *right << endl; 
                break;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }
    return 0;
}

