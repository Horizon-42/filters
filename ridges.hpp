#include "opencv4/opencv2/opencv.hpp"
using namespace cv;

void sortByAbs(const Mat &src, Mat &dst, int axis = -1,
               int order = SORT_ASCENDING);

void divideNonzero(const Mat &src1, const Mat &src2, Mat &dst, double cval = 1e-10);