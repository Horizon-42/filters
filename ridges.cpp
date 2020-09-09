#include "ridges.hpp"

void sortByAbs(const Mat &src, Mat &dst, int axis, int order) {
  Mat absData = cv::abs(src);
  switch (axis) {
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

  default:
    sortIdx(absData, dst, SORT_EVERY_COLUMN + order);
    break;
  }
}