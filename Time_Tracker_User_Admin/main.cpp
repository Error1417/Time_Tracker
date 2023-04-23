/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 03-28-23 @10 PM
 * Purpose:  survey project v1
 * 
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string> //string
#include <cstring> //c-strings
#include <cctype> // tolower()
#include <cmath>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "User.h"
#include "Admin.h"
#include "Time.h"
#include "Date.h"
#include "timer.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));

    int choice = 0;
    cout << "Welcome to Time Tracker!" << endl;
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: ReadInputFile()\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            case 1: // Admin login
            {
                Admin admin;
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
                User user1;
                user1.signUp();                 
                //user1.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {       
                
                Admin admin1;
                if(admin1.isUsrLogin()){
                    
                    cout<<"\n\nUser login was successful.\n"; 
                    //cout<<"\n inside main()";
                    //admin.printAdUsr();                    
                    
                    
                    // Create new User & copy admin values to user
                    User user2;
                    admin1.copy2Usr(user2);    
                    cout << "\nWelcome " << user2.getName();
                    user2.printUsr(); 
                    
                    //############################################################
                    //Time tracker code
                    
                    char resp;
                    int timeHolder;

                    Time now;
                    Date today;
                    Timer timer;

                    cout << endl << endl;
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
                 
                    if (timeHolder < 60) {
                        timeHolder = 1;
                    }
                    else if(timeHolder >=60){
                        timeHolder = timeHolder/60;
                    }
                    
                    
                    
                    long recLoc = admin1.getBegnFile();
                    
                    user2.setHiScore(timeHolder);
                    user2.reWrtBin(recLoc);

                    user2.printUsr();
                    admin1.findByIndx(user2.getNumRec());
                    admin1.printAdUsr();
                    //############################################################                      
                }
                break;
            }             
            case 4: // Read inputs to fill User binary with records
            {
                User user5;
                user5.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }
    
    return 0;
}