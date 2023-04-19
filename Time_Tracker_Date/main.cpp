/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ismael Perez
 *
 * Created on March 24, 2023, 4:46 PM
 */

#include <cstdlib>
#include <iostream>
#include "Time.h"
#include "Date.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Time now;
    Date today;
    
    today.printDate(); // print function for the time
    now.printTime(); // print function for the time
    return 0;
}

