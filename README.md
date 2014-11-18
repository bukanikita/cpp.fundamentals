programming_exercises
=====================

Programming Exercises for trainings.

Please make builds in build folder.

All steps:

1. mkdir build

2. cd build

3. cmake .. -G "Visual Studio 11 Win64" (or different compiler)

CMakeLists.txt builds all tasks in one solution, which has name "all_programming_exercises".

But 18_task_1 and 18_task_3 build from Makefile, because VS 2012 can't build these tasks.
To build them use nmake and executable files will be in root directory.