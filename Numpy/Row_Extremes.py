import numpy as np


def row_extremes(data: list) -> np.ndarray:
    """
    Returns float64 rows of maxima, maximum indices, minima, and minimum indices.
    """
    data = np.array(data, dtype=np.float64)
    max = data.max(axis=1)
    col_max = data.argmax(axis=1)
    min = data.min(axis=1)
    col_min = data.argmin(axis=1)
    return np.stack([max, col_max, min, col_min]).astype(np.float64)
    
