#ifndef _KEPLER_JAX_PYBIND11_KERNEL_HELPERS_H_
#define _KEPLER_JAX_PYBIND11_KERNEL_HELPERS_H_

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <type_traits>

#include "kernel_helpers.h"

namespace kepler_jax {

template <typename T>
pybind11::bytes PackDescriptor(const T& descriptor) {
  return pybind11::bytes(PackDescriptorAsString(descriptor));
}

template <typename T>
pybind11::capsule EncapsulateFunction(T* fn) {
  return pybind11::capsule(bit_cast<void*>(fn), "xla._CUSTOM_CALL_TARGET");
}

}  // namespace kepler_jax

#endif