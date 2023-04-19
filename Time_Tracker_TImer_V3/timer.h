/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   timer.h
 * Author: error
 *
 * Created on April 2, 2023, 1:13 PM
 */

#ifndef TIMER_H
#define TIMER_H
#include<chrono>

class Timer {
private:
    bool running;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
public:
    Timer();
    void start();
    void stop();
    float elapsed() const;
};


#endif /* TIMER_H */

