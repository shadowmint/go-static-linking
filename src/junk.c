#include <junk.h>
#include <stdio.h>
#include <Python.h>
#include <_cgo_export.h>

static PyObject *xx_foo(PyObject *self, PyObject *args)
{
    (void) self;
    long i, j;
    long res;
    if (!PyArg_ParseTuple(args, "ll:foo", &i, &j))
        return NULL;
    res = i+j; /* XXX Do something here */
    MyFunc(i);
    return PyInt_FromLong(res);
}

/* List of functions defined in the module */
static PyMethodDef xx_methods[] = {
    {"foo",             xx_foo,         METH_VARARGS, PyDoc_STR("Example func")},
    {NULL,              NULL, METH_VARARGS, NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
"This is a template module just for instruction.");

PyMODINIT_FUNC
initxx(void)
{
    PyObject *m;

    /* Create the module and add the functions */
    m = Py_InitModule3("demo", xx_methods, module_doc);
    if (m == NULL)
        return;
}

int x(int y) {
  printf("Hello World\n");

  Py_SetProgramName("");
  Py_Initialize();
  PySys_SetPath(".");
  initxx();
  PyRun_SimpleString("from sample import s\ns()");
  Py_Finalize();

  return y;
}
