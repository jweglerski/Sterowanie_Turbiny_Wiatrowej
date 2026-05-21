#pragma once
#include <iostream>
#include <chrono>
class PID
{
private:
    double kp;
    double ki;
    double kd;
    double e;
    double i;
    double lastE;
    std::chrono::steady_clock::time_point lastTime;
    std::chrono::steady_clock::time_point now;
    bool firstUpdate;
    double dt();
    void error(double target, double pomiar);
    void integer();
public:
    PID(double kp, double ki, double kd);

    double update(double target, double pomiar);
    void reset();
};