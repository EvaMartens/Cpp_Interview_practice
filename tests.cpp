//
// Created by epm04 on 04/02/2024.
//

#include <iostream>
#include "tests.h"
#include "fibbonaci.h"

//------------------------------------------------------------------------------------------------------


//functions
void fibFunctionsTest(){ //WARNING: calls one recursive function fibX, which can massively slow performance
    //Best to choose inputs between 1-20
    std::cout << "This function calls one recursive function, which massively slows performance." << std::endl;
    std::cout << "Best to choose smaller inputs between 1 - 15" << std::endl;
    int error;
    int nth;
    do {
        error = 0;
        std::cout << "Please select the Nth fibbonacci number you would like to find" << std::endl;
        std::cin >> nth;

        if(std::cin.fail()){
            std::cout << "Please enter a valid integer option" << std::endl;
            error = 1;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
    } while(error == 1);

    std::cout << "C++ Fibbonaci numbers code practice!" << std::endl;

    //Fibonnaci recursive algorithm
    // - slow bc of recursive call stack
    // - 2 ^ n timecomplexity -> levels of recursive tree times doubling of leaf nodes
    std::cout << "Nth fib according to fibX: " << nth << " is " << fibX(nth) << std::endl;

    //Optimised for space comp
    std::cout << "Nth fib according to fibSpaceCompOpt: " << nth << " is " << fibSpaceComOpt(nth) << std::endl;

    //Dynamic programming
    std::cout << "Nth fib according to fibDynProg: " << nth << " is " << fibDynProg(nth) << std::endl;
}

//------------------------------------------------------------------------------------------------------
    //setter Methode
    void Test::setTestTypeCall() {
        int error;
        char testTypeCallChoice;

        do{
            error = 0;

            std::cout << "Please select the test you would like to run" << std::endl;
            std::cout << "f = fibbonaci function tests" << std::endl;
            //----------> and more auto tests here when written
            //std::cout << "" << std::endl;
            //std::cout << "" << std::endl;
            std::cin >> testTypeCallChoice;

            //match against valid input choices
            int match = 0; //no match
            for(char c : inputAlphabet){
                if(testTypeCall == c){
                    match = 1; //match found
                }
            }

            if(match == 0){
                error = 1;
                std::cout << "Please view valid input choices" << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

        }while(error == 1);

        //once valid choice is found, assign char value
        this->testTypeCall = testTypeCallChoice;
    }

    //constructors
    Test::Test() {
        testTypeCall = 'x'; //x is reserved character for empty test

    }

    //test constructor which checks that the input for the char matches the valid input alphabet
    Test::Test(char testTypeC){
        testTypeCall = testTypeC;
        int valid = 0;
        for(char const c : inputAlphabet){
            if(c == testTypeC){
                valid = 1;
                break;
            }
        }

        if(valid == 0){
            setTestTypeCall();
        }

        switch(std::tolower(testTypeCall)) {
            case 'f':
                this->runTestEnum = fibbonacci;
                break;
        }

        runTest();

    }

void Test::runTest() {
    switch(runTestEnum){
        case fibbonacci:
            fibFunctionsTest();
            break;
        default:
            std::cout << "The test of type " << this->runTestEnum << " cannot be run";
            break;
    }
}

Test::~Test() {
}


