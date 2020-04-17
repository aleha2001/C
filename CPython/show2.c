#include <Python.h>

static PyObject *py_plus(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *pItem;
  Py_ssize_t n;
  int i;

  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
    }
  
  n = PyList_Size(pList);
  return Py_BuildValue("n",n);
}
  

/* ��������� ������ ������ */
static PyMethodDef ownmod_methods[] = {
{ 
    "pluss",          // �������� ������� ������ python
     py_plus,        // ������� C
     METH_VARARGS,   // ������, ����������, ��� ������� � ��� � �����������
     "plus function" // ������������ ��� ������� ������ python
},
{ NULL, NULL, 0, NULL } 
// ��� ���������� sentiel. ������� �� ��������� ��������� 
// � ��� �� ����, ���� ������� ������� ������ ���� ������, � ��� ���� ���� ���������
};

/* ��������� ��� ������ */
static PyModuleDef simple_module = {    
    PyModuleDef_HEAD_INIT,   // ������������ ������
    "my_pluss",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // ���� �������� ������ ������
};

// � �������� ������� ����������� ������ ���� ������� PyInit
PyMODINIT_FUNC PyInit_my_pluss(void) {
      PyObject* m;
      // ������� ������
      m = PyModule_Create(&simple_module);
      // ���� ��� ���������, �� ��� �������� �� ��������
      if (m == NULL)
          return NULL;
      return m;
}