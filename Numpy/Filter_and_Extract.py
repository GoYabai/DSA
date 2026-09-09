import numpy as np

def filter_and_extract(data, row_start, row_stop, threshold):
    """
    Returns: 1D ndarray of float64
    """
    data = np.array(data, dtype=np.float64)
    data = data[row_start:row_stop]
    mask = data > threshold
    cnt = np.sum(data > threshold)
    if cnt == 0:
        return np.empty((0,))
    else:
        return data[mask].flatten()