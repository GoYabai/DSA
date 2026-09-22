import numpy as np


def compare_correlations(a: list, b: list) -> np.ndarray:
    """
    Returns float64 correlation matrices for a, b, and their combined rows.
    """
    comb = np.concatenate([a, b], axis=0)
    corr_a = np.corrcoef(a, rowvar=False)
    corr_b = np.corrcoef(b, rowvar=False)
    corr_comp = np.corrcoef(comb, rowvar=False)
    return np.stack([corr_a, corr_b, corr_comp])