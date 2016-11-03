AM_CFLAGS = \
	-fstack-protector -Wall -pedantic			\
	-Wstrict-prototypes -Wundef -fno-common 		\
	-Werror-implicit-function-declaration 			\
	-Wformat -Wformat-security -Werror=format-security 	\
	-Wconversion -Wunused-variable -Wunreachable-code 	\
	-Wall -W -D_FORTIFY_SOURCE=2 -std=c11			\
	-DGDK_VERSION_MAX_ALLOWED=GDK_VERSION_3_16 		\
	-DGDK_VERSION_MIN_REQUIRED=GDK_VERSION_3_16		\
	-DGLIB_VERSION_MAX_ALLOWED=GLIB_VERSION_2_44		\
	-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_44

EXTRA_DIST =

noinst_PROGRAMS = \
	testing-applet

testing_applet_SOURCES = \
	src/main.c \
	src/win-query.h \
	src/win-query.c

testing_applet_CFLAGS = \
	$(GTK_CFLAGS) \
	$(GIO_CFLAGS) \
	$(WNCK_CFLAGS) \
	$(AM_CFLAGS)

testing_applet_LDADD = \
	$(GTK_LIBS) \
	$(GIO_LIBS) \
	$(WNCK_LIBS)
