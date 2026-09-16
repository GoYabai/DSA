import numpy as np


def normalize(data):
    """Returns: np.ndarray of shape (m, n), z-score normalized per column"""
    data = np.array(data, dtype=np.float64)
    data_mean = data.mean(axis=0, keepdims=True)
    data_std = data.std(axis=0, keepdims=True)
    return (data - data_mean) / data_std