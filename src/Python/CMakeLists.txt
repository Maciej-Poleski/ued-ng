find_package(PythonLibs REQUIRED)
execute_process ( COMMAND python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())" )

