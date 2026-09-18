import numpy as np


def sort_with_indices(data, axis):
    """Returns: np.ndarray of shape (2, m, n), stacked sorted values and sort indices"""
    s = np.sort(data, axis=axis)
    s_id = np.argsort(data, axis=axis)
    return np.stack((s, s_id)).astype(np.float64)