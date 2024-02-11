//
// Created by epm04 on 04/02/2024.
//

#ifndef EAPRAC_TESTS_H
#define EAPRAC_TESTS_H
//the following array summerizes possible coices for input in the test class setter
const char inputAlphabet[3] = {'f', 'F'};
enum testType { fibbonacci = 'f'};
//f & F = fibFunctionsTest()
//'x' is default and not associated with test

//function signitures
void fibFunctionsTest();
class Test {
private:
    char testTypeCall;
    enum testType runTestEnum;

protected:
    //setter Methode
    void setTestTypeCall();

public:

    //constructors
    Test();

    //test constructor which checks that the input for the char matches the valid input alphabet
    Test(char testTypeC);

    //destructor
    virtual ~Test();

    void runTest();

};

//Find out how to write header file for cpp file with class

#endif //EAPRAC_TESTS_H
