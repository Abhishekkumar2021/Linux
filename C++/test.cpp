#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    int real,imaginary;
    public:
    ComplexNumbers(int r,int i){
        real = r;
        imaginary= i;
    }
    void plus(ComplexNumbers &b){
        this->real = this->real+ b.real;
        this->imaginary = this->imaginary + b.imaginary;
    }
   void multiply(ComplexNumbers &b){
       int temp = this->real; 
       this->real = this->real*b.real - this->imaginary*b.imaginary;
       this->imaginary = temp*b.imaginary + this->imaginary*b.real;
   }
    void print(){
        if(imaginary>=0)
            cout<<real<<" + i"<<imaginary;
        else cout<<real<<" - i"<<(0-imaginary);
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}