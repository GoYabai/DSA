import numpy as np

def original_and_clipped(data, row_idx, lo, hi):
    """
    Returns: 2D ndarray of float64 with shape (2, ncols)
    """
    data = np.array(data, dtype=np.float64)
    row = data[row_idx].copy()
    clip = np.clip(data[row_idx], lo, hi)
    row = row.reshape(1, -1)
    clip = clip.reshape(1, -1)
    return np.concatenate((row, clip), axis=0)