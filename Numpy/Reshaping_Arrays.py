import numpy as np

def reshape_array(data, operation):
    """
    Returns: ndarray of float64 with shape determined by the operation
    """
    data = np.array(data, dtype=np.float64)
    if operation == "flatten":
        return data.flatten()
    elif operation == "transpose":
        return data.T
    else:
        return np.expand_dims(data, axis=0)
