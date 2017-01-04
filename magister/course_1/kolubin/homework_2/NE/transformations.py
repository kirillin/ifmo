#!/bin/env python
# homogeneous transformations are fun!
import math
import numpy as np


# Euler angels ZYZ
def get_orientation_matrix(phi, theta, psi):
    r_phi = rotation_matrix(phi, (0, 0, 1))
    r_theta = rotation_matrix(theta, (0, 1, 0))
    r_psi = rotation_matrix(psi, (0, 0, 1))
    h = concatenate_matrices(r_phi, r_theta, r_psi)
    return h[:3, :3]


def unit_vector(data, axis=None, out=None):
    if out is None:
        data = np.array(data, dtype=np.float64, copy=True)
        if data.ndim == 1:
            data /= math.sqrt(np.dot(data, data))
            return data
    else:
        if out is not data:
            out[:] = np.array(data, copy=False)
        data = out
    length = np.atleast_1d(np.sum(data * data, axis))
    np.sqrt(length, length)
    if axis is not None:
        length = np.expand_dims(length, axis)
    data /= length
    if out is None:
        return data


def rotation_matrix(angle, direction, type=np.float, point=None):
    sina = math.sin(angle)
    cosa = math.cos(angle)
    direction = unit_vector(direction[:3])
    # rotation matrix around unit vector
    R = np.array(
        (
            (cosa, 0.0, 0.0),
            (0.0, cosa, 0.0),
            (0.0, 0.0, cosa)), dtype=type)
    R += np.outer(direction, direction) * (1.0 - cosa)
    direction *= sina
    R += np.array(
        ((0.0, -direction[2], direction[1]),
        (direction[2], 0.0, -direction[0]),
        (-direction[1], direction[0], 0.0)), dtype=type)
    M = np.identity(4)
    M[:3, :3] = R
    if point is not None:
        # rotation not around origin
        point = np.array(point[:3], dtype=type, copy=False)
        M[:3, 3] = point - np.dot(R, point)
    return M


def translation_matrix(direction):
    M = np.identity(4)
    M[:3, 3] = direction[:3]
    return M


def concatenate_matrices(*matrices):
    M = np.identity(4)
    for i in matrices:
        M = np.dot(M, i)
    return M