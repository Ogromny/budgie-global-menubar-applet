AC_INIT([Budgie Global Menubar Applet], 10.2.7, [ikey@solus-project.com], [budgie-global-menubar-applet], [https://solus-project.com/])
AM_INIT_AUTOMAKE([-Wno-portability no-dist-gzip dist-xz foreign subdir-objects 1.9 tar-ustar])
AC_PROG_CC
AC_PROG_CC_STDC
AC_PREFIX_DEFAULT(/usr/local)
AM_SILENT_RULES([yes])
AC_CONFIG_MACRO_DIR([m4])
LT_PREREQ(2.2)
LT_INIT([disable-static])

GLIB_GSETTINGS

# Build requirements
m4_define([gtk_required_version], [3.16.0])
m4_define([glib_required_version], [2.44.0])
m4_define([wnck_required_version], [3.14.0])

PKG_CHECK_MODULES(GTK,
                 [
                   gtk+-3.0 >= gtk_required_version
                 ]
)

PKG_CHECK_MODULES(GIO,
                 [
                   gobject-2.0 >= glib_required_version
                   gio-unix-2.0 >= glib_required_version
                 ]
)

PKG_CHECK_MODULES(WNCK,
                 [
                   libwnck-3.0  >= wnck_required_version
                 ]
)


AC_CONFIG_FILES([Makefile])

AC_OUTPUT

AC_MSG_RESULT([
        budgie-global-menubar-applet $VERSION
        ===================================

        prefix:                 ${prefix}
        libdir:                 ${libdir}
        sysconfdir:             ${sysconfdir}
        exec_prefix:            ${exec_prefix}
        bindir:                 ${bindir}
        datarootdir:            ${datarootdir}

        compiler:               ${CC}
        cflags:                 ${CFLAGS}
        ldflags:                ${LDFLAGS}
])
