#include <junk.h>
#include <stdio.h>
#include <Python.h>

int x(int y) {
  printf("Hello World\n");

  Py_SetProgramName("");
  Py_Initialize();
  PyRun_SimpleString("print(\"Hello Python\")");
  Py_Finalize();

  return y;
}
