import numpy as np


def arrays(arr):
    return np.array(arr[::-1], float)


arr = input().strip().split(' ')
result = arrays(arr)
print(result)