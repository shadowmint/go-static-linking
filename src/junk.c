#include <junk.h>
#include <stdio.h>
#include <Python.h>

int x(int y) {
  printf("Hello World\n");

  Py_SetProgramName("");
  Py_Initialize();
  PySys_SetPath(".");
  PyRun_SimpleString("from sample import s\ns()");
  Py_Finalize();

  return y;
}
