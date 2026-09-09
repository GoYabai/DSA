import numpy as np

def row_summary(data, threshold):
    """Returns: np.ndarray of shape (3, m, n), stacked element mask, any-filtered, all-filtered"""
    data = np.array(data, dtype=np.float64)
    mask1 = data > threshold
    data1 = np.where(mask1, 1, 0)
    mask2 = np.any(data > threshold, axis=1, keepdims=True)
    data2 = np.where(mask2, data, 0)
    mask3 = np.all(data > threshold, axis=1, keepdims=True)
    data3 = np.where(mask3, data, 0)
    return np.stack((data1, data2, data3))