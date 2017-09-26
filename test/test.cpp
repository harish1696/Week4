// "Copyright [2017] <Harish>"  [legal/copyright]

#include <gtest/gtest.h>

#include <PID.hpp>

// First test: Testing the compute function
TEST(computeMethod, should_pass) {
    PID pid;
    pid.setGain(3, 0, 0);  // Set proportional gain to 3
    EXPECT_EQ(9, pid.compute(5, 2));  // Calculate (5-2)*kp
    EXPECT_EQ(18, pid.compute(10, 4));  // Calculate (10-4)*kp
}

// Second Test: Testing the initialize function
TEST(initializeMethod, should_pass_kp_ki_kd) {
  PID pid;
  pid.initialize();
  double kp = pid.get_kp();
  double ki = pid.get_ki();
  double kd = pid.get_kd();
  EXPECT_EQ(0, kp);
  EXPECT_EQ(0, ki);
  EXPECT_EQ(0, kd);
}

// Third test: Testing the setGain function
TEST(setGainMethod, should_pass_kp_ki_kd) {
    PID pid;
    pid.setGain(2, 0, 0);
    double kp = pid.get_kp();
    double ki = pid.get_ki();
    double kd = pid.get_kd();
    EXPECT_EQ(2, kp);
    EXPECT_EQ(0, ki);
    EXPECT_EQ(0, kd);
}



