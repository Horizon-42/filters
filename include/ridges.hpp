#include "opencv4/opencv2/opencv.hpp"
#include "utils.hpp"
using namespace cv;
namespace filters
{
    void sortByAbs(const Mat &src, Mat &dst, int axis = -1,
                   int order = SORT_ASCENDING);

    void divideNonzero(const Mat &src1, const Mat &src2, Mat &dst,
                       double cval = 1e-10);
    Mat checkSigmas(InputArray sigmas);

    void computeHessianEigenvalues(const Mat &image, Mat &hessianEigenvalues, double sigma, SORT sorting = NON, MODE mode = CONSTANT, double cval = 0);
} // namespace filters
