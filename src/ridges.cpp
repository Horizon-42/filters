#include "ridges.hpp"
namespace filters
{
  void divideNonzero(const Mat &src1, const Mat &src2, Mat &dst, double cval)
  {
    auto denominator = Mat(src2.rows, src2.cols, src2.type(), Scalar(1e-10));
    Mat nonZeroMask = src2 != 0;
    src2.copyTo(denominator, nonZeroMask);
    divide(src1, denominator, dst);
  }

  void sortByAbs(const Mat &src, Mat &dst, int axis, int order)
  {
    Mat absData = cv::abs(src);
    switch (axis)
    {
    case 0:
      //   sort row
      sortIdx(absData, dst, SORT_EVERY_COLUMN + order);
      break;
    case 1:
      sortIdx(absData, dst, SORT_EVERY_ROW + order);
      break;
    case 2:
      // 通道值排序
      absData = absData.reshape(1, absData.rows * absData.cols);
      sort(absData, dst, SORT_EVERY_ROW + order);
      dst = dst.reshape(src.channels(), src.rows);
    default:
      sortIdx(absData, dst, SORT_EVERY_COLUMN + order);
      break;
    }
  }

  Mat checkSigmas(InputArray sigmas)
  {
    Mat sgms = sigmas.getMat();
    assert((sgms.depth() == CV_64F || sgms.depth() == CV_32F) && "sigmas must be float or double data.");
    auto nonNegetive = sgms < 0.0;
    if (cv::countNonZero(nonNegetive) > 0)
    {
      throw "sigmas has negative value";
    }
    return sgms.reshape(1, 1);
  }

  void computeHessianEigenvalues(const Mat &image, double sigma,
                                 SORT sorting = NON, MODE mode = CONSTANT, double cval = 0)
  {
    Mat img;
    image.convertTo(img, CV_64F);
    computeHessianEigenvalues(img, sigma, sorting, mode, cval);
  }
} // namespace filters
