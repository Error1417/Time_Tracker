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
#include "timer.h"
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    char resp;
    int timeHolder;
    
    Time now;
    Date today;
    Timer timer;
    
    today.printDate(); // print function for the time
    now.printTime(); // print function for the time
    
    cout << endl;
    cout << "Time is now being recorded." << endl;
    
    timer.start(); // starts the timer
    while(true){
        cout << "When finished recording your time type 'q' or 'Q' to exit." << endl;
        cin >> resp;
        if(resp == 'q'||resp=='Q') break;
    }
    
    timer.stop();//stops the timer
    //time holder going to be needed for when times are combined with the time in the binary files
    
    timeHolder = timer.elapsed();
    
    cout << "Elapsed time: " << timeHolder << " seconds." << endl;
    
    return 0;
}

