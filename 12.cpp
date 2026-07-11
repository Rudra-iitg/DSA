#include <iostream>
using namespace std;

// Base class for dynamic_cast example
class Animal {
public:
    virtual ~Animal() {}
    virtual void speak() { cout << "Animal sound" << endl; }
};

// Derived class for dynamic_cast example
class Dog : public Animal {
public:
    void speak() override { cout << "Woof! Woof!" << endl; }
    void wagTail() { cout << "Wagging tail..." << endl; }
};

int main(){
    cout << "========== TYPECASTING IN C++ ==========" << endl << endl;
    
    // ===== 1. IMPLICIT CASTING (Automatic) =====
    cout << "1. IMPLICIT CASTING (Automatic Conversion)" << endl;
    cout << "-------------------------------------------" << endl;
    int intNum = 10;
    float floatNum = intNum;  // int implicitly converted to float
    cout << "int to float: " << intNum << " becomes " << floatNum << endl;
    
    int a = 5;
    double b = a;  // int to double
    cout << "int to double: " << a << " becomes " << b << endl << endl;
    
    // ===== 2. EXPLICIT C-STYLE CASTING =====
    cout << "2. C-STYLE CASTING (Explicit)" << endl;
    cout << "-------------------------------------------" << endl;
    float pi = 3.14159;
    int piInt = (int)pi;  // C-style casting
    cout << "float to int (C-style): " << pi << " becomes " << piInt << endl;
    
    double decimal = 99.99;
    int decimalInt = (int)decimal;
    cout << "double to int (C-style): " << decimal << " becomes " << decimalInt << endl << endl;
    
    // ===== 3. STATIC_CAST =====
    cout << "3. STATIC_CAST (Compile-time checking)" << endl;
    cout << "-------------------------------------------" << endl;
    float temperature = 98.6;
    int tempInt = static_cast<int>(temperature);
    cout << "Temperature (float to int): " << temperature << " becomes " << tempInt << endl;
    
    int number = 42;
    double doubleNum = static_cast<double>(number);
    cout << "Number (int to double): " << number << " becomes " << doubleNum << endl;
    
    // static_cast with pointers
    void* voidPtr = &number;
    int* intPtr = static_cast<int*>(voidPtr);
    cout << "void pointer to int pointer: " << *intPtr << endl << endl;
    
    // ===== 4. DYNAMIC_CAST (Runtime checking with RTTI) =====
    cout << "4. DYNAMIC_CAST (Runtime checking)" << endl;
    cout << "-------------------------------------------" << endl;
    Animal* animal = new Dog();
    Dog* dog = dynamic_cast<Dog*>(animal);
    
    if (dog != nullptr) {
        cout << "Successfully cast Animal* to Dog*" << endl;
        dog->speak();
        dog->wagTail();
    } else {
        cout << "Cast failed" << endl;
    }
    
    // Trying to cast to wrong type
    Animal* genericAnimal = new Animal();
    Dog* wrongDog = dynamic_cast<Dog*>(genericAnimal);
    if (wrongDog == nullptr) {
        cout << "Cast failed (correctly - Animal is not a Dog)" << endl;
    }
    cout << endl;
    
    // ===== 5. CONST_CAST (Remove/Add const) =====
    cout << "5. CONST_CAST (Remove/Add const)" << endl;
    cout << "-------------------------------------------" << endl;
    const int constValue = 100;
    // int& refValue = constValue;  // ERROR: cannot bind non-const reference to const
    
    // Using const_cast to remove const
    const int* constPtr = &constValue;
    int* nonConstPtr = const_cast<int*>(constPtr);
    cout << "Original const value: " << constValue << endl;
    cout << "Through const_cast pointer: " << *nonConstPtr << endl;
    
    // Adding const
    int normalValue = 50;
    const int* addedConstPtr = const_cast<const int*>(&normalValue);
    cout << "Normal int made const: " << *addedConstPtr << endl << endl;
    
    // ===== 6. REINTERPRET_CAST (Dangerous - raw bit conversion) =====
    cout << "6. REINTERPRET_CAST (Dangerous - Raw Bit Conversion)" << endl;
    cout << "-------------------------------------------" << endl;
    int originalInt = 65;
    char* charPtr = reinterpret_cast<char*>(&originalInt);
    cout << "int 65 reinterpreted as char: " << *charPtr << endl;
    cout << "WARNING: This casts between unrelated types!" << endl << endl;
    
    // ===== 7. COMPARISON TABLE =====
    cout << "7. COMPARISON OF CASTING METHODS" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "IMPLICIT:      Automatic, no syntax needed, can lose precision" << endl;
    cout << "C-STYLE:       (type)value, unsafe, hard to find in code" << endl;
    cout << "STATIC_CAST:   static_cast<type>(value), checked at compile-time" << endl;
    cout << "DYNAMIC_CAST:  dynamic_cast<type>(ptr), checked at runtime (RTTI)" << endl;
    cout << "CONST_CAST:    const_cast<type>(ptr), removes/adds const" << endl;
    cout << "REINTERPRET:   reinterpret_cast<type>(ptr), unsafe raw conversion" << endl << endl;
    
    // ===== 8. BEST PRACTICES EXAMPLE =====
    cout << "8. BEST PRACTICES" << endl;
    cout << "-------------------------------------------" << endl;
    
    float value = 123.456;
    int result = static_cast<int>(value);  // GOOD: explicit and safe
    cout << "GOOD: static_cast<int>(" << value << ") = " << result << endl;
    
    // Avoid: int result2 = (int)value;  // BAD: C-style cast
    
    // Cleanup
    delete animal;
    delete genericAnimal;
    
    return 0;
}
// This is just for github