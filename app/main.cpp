// "Copyright [2017] <Harish>"  [legal/copyright]

#include <iostream>
#include <PID.hpp>

using std::cout;
using std::cin;
using std::endl;

int main() {
    double p_gain = 0.0;
    double i_gain = 0.0;
    double d_gain = 0.0;
    double setpoint;
    double vel;
    double output;

    // initializing object of class PID
    PID pid;
    // initialize members of class PID
    pid.initialize();

    // get the kp, ki, kd values from user
    cout << "Enter the Kp, Ki and Kd values : ";
    cin >> p_gain >> i_gain >> d_gain;
    cout << endl;

    // update the gain values
    pid.setGain(p_gain, i_gain, d_gain);

    // get the setpoint and actual velocity from user
    cout << "Enter the setpoint (desired velocity) : ";
    cin >> setpoint;
    cout << endl;
    cout << "Enter the actual velocity : ";
    cin >> vel;
    cout << endl;

    // compute the pid value
    output = pid.compute(setpoint, vel);

    return 0;
}
