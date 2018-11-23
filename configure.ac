AC_PREREQ([2.63])

AC_INIT([ping-pong],
        [1.0.0],
        [uabinle@gmail.com])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(m4)
AM_INIT_AUTOMAKE()

# Checks for programs.
AC_PROG_CC_C99
AC_PROG_CPP
AM_PROG_AR

# Use the C language and compiler for the following checks
AC_LANG([C])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_CONFIG_FILES([
        Makefile
        src/Makefile
	])

LT_INIT
AC_OUTPUT
