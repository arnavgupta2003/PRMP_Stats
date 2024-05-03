# Introduction

Welcome to the test bed for evaluating performance benchmarks and experiments. In this repository, you'll find the necessary resources for conducting experiments as outlined in the provided PDF.

## Benchmarks and Experiments

### Overview
The repository includes both sequential and parallel versions of benchmarks for experimental evaluation. These benchmarks are to be used according to the deadlines specified below.

### Deadlines and Experiments
1. **Deadline-1**: Evaluate speedup over sequential for worker counts of 5, 10, 15, and 20. Compare with default hclib-light.
2. **Deadline-2**: Assess speedup over sequential (with/without deadline implementation), total tasks created, and steal to task ratio for worker counts of 5, 10, 15, and 20.
3. **Deadline-3**: Measure speedup over sequential (with/without deadline implementation) for worker counts of 20 in NUMA and both 10 and 20 in trace/replay mode.
4. **Deadline-4**: Determine speedup over sequential (with/without deadline implementation) for a worker count of 20 and calculate energy savings relative to default hclib-light.

### Experiment Guidelines
- For calculating execution time, take the average of five invocations in each experiment.
- Ensure benchmarks are used as provided without modifications except for specific cases as mentioned.


# Test Bench Architecture

## General Information
- **Architecture:** x86_64
- **CPU op-mode(s):** 32-bit, 64-bit
- **Address sizes:** 46 bits physical, 48 bits virtual
- **Byte Order:** Little Endian

## CPU Specifications
- **CPU(s):** 32
- **Vendor ID:** GenuineIntel
- **Model name:** Intel(R) Xeon(R) CPU E5-2683 v4 @ 2.10GHz
  - **CPU family:** 6
  - **Model:** 79
  - **Thread(s) per core:** 2
  - **Core(s) per socket:** 16
  - **Socket(s):** 1
  - **Stepping:** 1
  - **CPU(s) scaling MHz:** 96%
  - **CPU max MHz:** 3000.0000
  - **CPU min MHz:** 1200.0000

## Caches
- **L1d:** 512 KiB (16 instances)
- **L1i:** 512 KiB (16 instances)
- **L2:** 4 MiB (16 instances)
- **L3:** 40 MiB (1 instance)

## NUMA
- **NUMA node(s):** 1
- **NUMA node0 CPU(s):** 0-31
