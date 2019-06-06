//
//  main.cpp
//  C++ Project
//
//  Created by Evan Crabtree on 07/02/2019.
//  Copyright © 2019 QuantumFluctuator. All rights reserved.
//

#include <iostream>

using namespace std;

long add(long x, long y) {
    long z;
    __asm {
        mov rax, x      //copy x into RAX
        add rax, y      //add y to RAX
        mov z, rax      //move RAX into z for return
    }
    return z;
}

long sub(long x, long y) {
    long z;
    __asm {
        mov rax, x      //copy x into RAX
        sub rax, y      //subtract y from RAX
        mov z, rax      //move RAX into z for return
    }
    return z;
}

long mult(long x, unsigned long y) {
    long z;
    __asm {
        xor rcx, rcx    //set counter to 0
        xor rax, rax    //set total to 0
        mov rdx, y      //move y into RDX
        cmp rcx, rdx    //compare counter with RDX
        je endLoop      //jump to end if RDX is 0
    loop:
        add rax, x      //increment total by x
        add rcx, 1      //add 1 to counter
        cmp rcx, rdx    //compare counter with RDX
        jne loop        //if counter and RDX not equal, begin loop again
    endLoop:
        mov z, rax      //copy total into z
    }
    return z;
}

long divide(long x, long y) {
    long z;
    __asm {
        mov z, 0        //TODO: division
    }
    return z;
}

long rem(long x, long y) {
    long z;
    __asm {
        mov z, 0        //TODO: remainder
    }
    return z;
}

long power(long x, long y) {
    long z;
    __asm {
        mov z, 0        //TODO: powers
    }
    return z;
}

long fact(long x) {
    long z;
    __asm {
        mov z, 0        //TODO: factorial
    }
    return z;
}

long getX() {
    long x;
    cout << "Enter a value for x: ";
    cin >> x;           //read in x and return
    return x;
}

long getY() {
    long y;
    cout << "Enter a value for y: ";
    cin >> y;           //read in y and return
    return y;
}

void error(string errorType) {
    cout << "Error: " + errorType;
}

int main() {
    long x, y, z;
    char option;
    
    cout << "\r\n  + for add\r\n  - for subtract\r\n  * for multiply\r\n  / for divide\r\n  r for remainder\r\n  ^ for power\r\n  ! for factorial\r\n\r\nEnter an operation to perform: ";
    cin >> option;              //read in operation choice
    
    x = getX();                 //x is always accepted even if operation selected is invalid
    
    switch (option) {           //perform operation
        case '+':
            y = getY();
            z = add(x, y);
            break;
        case '-':
            y = getY();
            z = sub(x, y);
            break;
        case '*':
            y = getY();
            z = mult(x, y);
            break;
        case '/':
            y = getY();
            z = divide(x, y);
            break;
        case 'r':
            y = getY();
            z = rem(x, y);
            break;
        case '^':
            y = getY();
            z = power(x, y);
            break;
        case '!':
            z = fact(x);
            break;
        default:
            error("unkown command");    //invalid command
            z = 0;
            break;
    }
    
    cout << z << endl;                  //output z
    
    return 0;
}
