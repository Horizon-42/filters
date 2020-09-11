#include "opencv4/opencv2/opencv.hpp"
#include "ridges.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace cv;
using namespace std;
using namespace filters;

// int add(int a, int b) { return a + b; }
// TEST(testCase, test0) { EXPECT_EQ(add(2, 3), 5); }

TEST(test_ridges, testDivideNonZero) {
  Mat a = Mat(4, 4, CV_32FC1, Scalar(2.4));
  Mat b = Mat(4, 4, CV_32FC1, Scalar(0.6));
  b.at<float>(1, 1) = 0;
  Mat c;
  EXPECT_NO_THROW(divideNonzero(a, b, c));
  cout << c << endl;
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  // Mat a = Mat(4, 4, CV_32FC1, Scalar(2.4));
  // Mat b = Mat(4, 4, CV_32FC1, Scalar(0.6));
  // b.at<float>(1, 1) = 0;
  // Mat c;
  // divideNonzero(a, b, c);
  // EXPECT_NO_THROW(divideNonzero(a, b, c));
  // cout << c << endl;
}
