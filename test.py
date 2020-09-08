import numpy as np

if __name__ == "__main__":
    shape = (400, 400, 3)
    # 星号表示拆分元组为单个元素
    A = list(np.ix_(*[np.arange(i) for i in shape]))
    print(A)
    print([1, 2, 3])
    print(np.ix_(*[np.arange(2), np.arange(3)]))
