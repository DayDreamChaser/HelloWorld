import numpy as np

def diff(a, b):
    d = a - b
    return (d * d).sum() ** 0.5

def diag_mat_inver(A):
    return np.diagflat(1 / A.diagonal())

def iterat_solve(x, B, g, end_num, thres):
    cnt = 0
    for i in range(end_num):
        pre_x = x
        x = B @ pre_x + g
        if diff(pre_x, x) < thres:
            cnt += 1  # lower error cnt
            if cnt > (end_num / 100):
                break
    return x

def iter_jacobi(A, b, end_num, thres):
    # inital x as zero vector
    x = np.zeros(A.shape[0])
    
    # calc the iteral matrix and g for A
    D_inver = diag_mat_inver(A)
    B = np.eye(A.shape[0]) - D_inver @ A
    g = D_inver @ b
 
    return iterat_solve(x, B, g, end_num, thres)

if __name__ == "__main__":
    b = np.array([3, 15, 10])
    A = np.array([[10, -2, -1], [-2, 10, -1], [-1, -2, 5]])
    result = iter_jacobi(A, b, 100, 0)
    print("x = B * x + g\nA={0}\n\nb={1}\n\nresult x is:\n{2}".format(A, b, result))
