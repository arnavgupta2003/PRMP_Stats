## Runtime Performance Statistics


This repository showcases the performance statistics of a custom runtime developed for a course. The runtime aims to improve the execution speed of specific tasks compared to a baseline system. Here's a breakdown of the performance analysis in four parts:

### Deadline -1
**Part 1: Aim**

* **Goal:** You will have to implement a work-stealing runtime using Argobots and then use it as a backend for the HClib library. Your implementation of HCArgoLib would support the async-finish programming model supported by HClib by transforming the HClib async tasks into ULT and load-balancing it using a custom work-stealing implementation.


**Part 2: Results**

* **Speedup Graphs:** 
    !["SpeedUp Comparision Plot"](Speedup.png)
* **Textual Statistics:** 

| Threads | ArraySum | Iterative | Fibonacci | Qsort             |
|---------|----------|-----------|-----------|-------------------|
|         | Self     | Self      | Self      | Self Runtime      |
| 5       | 1        | 0.847782  | 0.026838  | 1.003372          |
| 10      | 1        | 0.843299  | 0.026504  | 1.010542          |
| 15      | 1        | 0.837315  | 0.026799  | 1.004442          |
| 20      | 1        | 0.831031  | 0.026735  | 1.003957          |
|         | Original | Original  | Original  | Original Runtime  |
| 5       | 3.281567 | 2.037524  | 4.145021  | 3.988324          |
| 10      | 3.261184 | 2.084188  | 8.269319  | 6.601486          |
| 15      | 3.268704 | 2.074764  | 12.25272  | 8.392688          |
| 20      | 3.176558 | 2.034565  | 12.64149  | 8.278623          |

**Part 3: Additional Information**

*  **Argobots Runtime Usage**

To use Argobots as the runtime environment for HCArgoLib, follow these steps:

1. **Download Argobots**:
   - Clone the Argobots repository from its master branch on GitHub using the following command:
     ```
     git clone https://github.com/pmodels/argobots.git
     ```

2. **Build and Install Argobots**:
   - Build and install Argobots in a separate directory outside your HClib project repository. It's important to keep the Argobots installation separate from your HClib project.
   - Instructions for building and installing Argobots are provided in the README.md file of the Argobots repository on GitHub.
   - In summary, you can build Argobots on an x86 processor using the following commands:
     ```
     cd argobots
     ./autogen.sh
     ./configure --prefix=/home/nsl/argobots-install
     make
     make install
     ```

3. **Build HCArgoLib**:
   - HCArgoLib is a shared library (.so) similar to HClib.
   - When building HCArgoLib, provide the path to the include folder inside the Argobots installation directory.
   - Use an environment variable to capture the path to the Argobots installation directory:
     ```
     export ARGOBOTS_INSTALL_DIR=/absolute/path/to/argobots/installation/directory
     ```

4. **Compilation**:
   - Refer to the Makefile in `argobots/examples/hellow_world/` for compiling a program using Argobots, and `hclib/test/Makefile` for compiling HClib's program.
   - You may need to make changes inside `hclib/inc/hclib.mak`, `hclib/src/Makefile.am`, and `hclib/Makefile.am`.

5. **Setting Environment Variables**:
   - Besides sourcing the path for HClib, set the `LD_LIBRARY_PATH` as follows to run applications using HCArgoLib:
     ```
     export LD_LIBRARY_PATH=$(ARGOBOTS_INSTALL_DIR)/lib:$LD_LIBRARY_PATH
     ```

6. **Running HCArgoLib Programs**:
   - HCArgoLib programs should execute without any changes.
   - For example, to run a program with HCArgoLib:
     ```
     HCLIB_WORKERS=4 ./fib
     ```
   - Here, `HCLIB_WORKERS` specifies the total number of execution streams to be used in Argobots.

By following these steps, you can seamlessly integrate HCArgoLib into your HClib projects and leverage the powerful features of Argobots for efficient parallel programming.

