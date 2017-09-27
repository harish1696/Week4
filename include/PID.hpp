// "Copyright [2017] <Harish>"  [legal/copyright]

#pragma once

#include<iostream>

// class PID with kp,ki,kd and compute method
class PID {
 public:
      void initialize();
      double get_kp();
      double get_ki();
      double get_kd();
      void setGain(double kp, double ki, double kd);
      double compute(double setpoint, double vel);
 private:
      double kp;
      double ki;
      double kd;
      double prevError;
      double iSum;
      double dt = 0.1;
};

// to compute output velocity with given setpoint and actual velocity
double PID::compute(double setpoint, double vel) {
  // Calculate error
  double error = setpoint - vel;

  // Proportional term
  double Pout = kp * error;

  // Integral term
  iSum += error * dt;
  double Iout = ki * iSum;

  // Derivative term
  double derivative = (error - prevError)/dt;
  double Dout = kd * derivative;

  // Calculate total output
  double output = Pout + Iout + Dout;

  // Save error to previous error
  prevError = error;

  return output;
}

// to initialize previous error and integral sum values
void PID::initialize() {
      this->prevError = 0.0;
      this->iSum = 0.0;
      this->kp = 0.0;
      this->ki = 0.0;
      this->kd = 0.0;
}

// to set the kp, ki & kd values
void PID::setGain(double kp, double ki, double kd) {
      this->kp = kp;
      this->ki = ki;
      this->kd = kd;
}

// returns the value of kp
double PID::get_kp() {
       return kp;
}

// returns the value of ki
double PID::get_ki() {
       return ki;
}

// returns the value of kd
double PID::get_kd() {
       return kd;
}
