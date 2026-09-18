import numpy as np


def summarize(data, axis):
    """Returns: np.ndarray of shape (4, k), rows are mean, std, min, max""" 
    return np.array([
    np.mean(data, axis=axis),
    np.std(data, axis=axis),
    np.min(data, axis=axis),
    np.max(data, axis=axis)
    ])