/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"

using namespace std;

int main(int argc, char* argv[])
{
    Node* in = new Node(2, nullptr);
    in->next = new Node(3, nullptr);
    in->next->next = new Node(4, nullptr);
    Node* evens = nullptr;
    Node* odds = nullptr;

    split(in, odds, evens);
    if (in == nullptr){
        cout << "in gone" << endl;
    }

    cout << (evens->value) << endl;
    cout << (evens->next->value) << endl;
    cout << (odds->value) << endl;
}
