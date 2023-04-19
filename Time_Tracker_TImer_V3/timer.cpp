/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "timer.h"

Timer::Timer()
    : running(false)
{
}

void Timer::start()
{
    if (!running) {
        running = true;
        startTime = std::chrono::high_resolution_clock::now();
    }
}

void Timer::stop()
{
    if (running) {
        running = false;
        endTime = std::chrono::high_resolution_clock::now();
    }
}

float Timer::elapsed() const
{
    if (running) {
        std::chrono::duration<float> elapsed = std::chrono::high_resolution_clock::now() - startTime;
        return elapsed.count();
    } else {
        std::chrono::duration<float> elapsed = endTime - startTime;
        return elapsed.count();
    }
}