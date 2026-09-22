import numpy as np


def quantize_and_frame(data: list, decimals: int, pad_width: int) -> np.ndarray:
    """
    Returns float64 slices of rounded, floored, and ceiling-rounded values with zero borders.
    """
    arr = np.array(data, dtype=np.float64)
    re = [np.round(arr, decimals), np.floor(arr), np.ceil(arr)]
    ans = [np.pad(r, pad_width=pad_width, mode='constant', constant_values=0.0) for r in re]
    return np.stack(ans)
