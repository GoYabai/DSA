import numpy as np


def tile_diff(data: list, reps: int) -> np.ndarray:
    """
    Returns float64 slices of tiled values and next-row differences with a final zero row.
    """
    data = np.array(data)
    T = np.tile(data, (reps, 1))
    diff_T = np.diff(T, axis=0)
    D = np.pad(diff_T, pad_width=((0, 1), (0, 0)), mode='constant', constant_values=0.0)
    return np.stack([T,D])