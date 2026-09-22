import numpy as np


def winsorize(data: list, lo_q: float, hi_q: float) -> np.ndarray:
    """
    Returns float64 slices of clipped values, lower mask, and upper mask.
    """
    data = np.array(data, dtype=np.float64)
    lo = np.percentile(data, lo_q, axis=0)
    hi = np.percentile(data, hi_q, axis=0)
    clip = np.clip(data, lo, hi)
    lo_mask = (data < lo).astype(np.float64)
    hi_mask = (data > hi).astype(np.float64)
    return np.stack([clip, lo_mask, hi_mask])
