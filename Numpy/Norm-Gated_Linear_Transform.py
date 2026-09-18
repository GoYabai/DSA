import numpy as np


def norm_gate(X, W, threshold):
    """Returns: np.ndarray of shape (n, k), gated projection where rows below threshold are zeroed"""
    X = np.array(X, dtype=np.float64)
    W = np.array(W, dtype=np.float64)
    Z = X @ W
    return np.where(np.linalg.norm(Z, axis=1, keepdims=True) < threshold, 0, Z)