AC_PREREQ(2.61)

# package version number (not shared library version)
# odd micro numbers indicate in-progress development
# even micro numbers indicate released versions
m4_define(moblin_panel_date_time_version_major, 0)
m4_define(moblin_panel_date_time_version_minor, 1)
m4_define(moblin_panel_date_time_version_micro, 0)

m4_define([moblin_panel_date_time_version],
          [moblin_panel_date_time_version_major.moblin_panel_date_time_version_minor.moblin_panel_date_time_version_micro])
m4_define([moblin_panel_date_time_api_version],
          [moblin_panel_date_time_version_major.moblin_panel_date_time_version_minor])

AC_INIT(moblin-panel-date-time, moblin_panel_date_time_version)
AM_INIT_AUTOMAKE(moblin-panel-date-time, moblin_panel_date_time_version)
AC_CONFIG_HEADERS(config.h)
AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_HOST
IT_PROG_INTLTOOL([0.35.0])

# Check for programs
AC_PROG_CC_STDC
AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_INSTALL
AC_ISC_POSIX
AC_HEADER_STDC
AM_PROG_CC_C_O

CFLAGS="$CFLAGS -Wall"

PKG_CHECK_MODULES(MPL, moblin-panel >= 0.50.0)
MOBLIN_PANELS_DIR=`$PKG_CONFIG --variable=moblin_panel_panels_dir moblin-panel`
AC_SUBST(MOBLIN_PANELS_DIR)

# enable pkg-config
PKG_PROG_PKG_CONFIG

PKG_CHECK_MODULES(DATETIME, glib-2.0
			clutter-1.0)

AC_SUBST(DATETIME_CFLAGS)
AC_SUBST(DATETIME_LIBS)

AC_ARG_ENABLE([moblin-desktop-file],
              [AC_HELP_STRING([--disable-moblin-desktop-file],
                              [Disable installation of moblin desktop file])],
              [enable_mdesktop=$enableval],
              [enable_mdesktop=yes])

AM_CONDITIONAL([ENABLE_MOBLIN_DESKTOP_FILE], [test "x$enable_mdesktop" = "xyes"])

AC_ARG_ENABLE([cache],
              [AC_HELP_STRING([--enable-cache],
                              [Enable Nbtk image cache generation])],
              [],
              [enable_cache=no])

AS_IF([test "x$enable_cache" = "xyes"],
      [
      AC_CHECK_PROG([NBTK_CREATE_IMAGE_CACHE],
                [nbtk-create-image-cache],
                [$(which nbtk-create-image-cache)])
])

AM_CONDITIONAL([ENABLE_CACHE],   [test "x$enable_cache" = "xyes"])

# i18n
AC_SUBST(ALL_LINGUAS)
AM_GLIB_GNU_GETTEXT
AC_DEFINE(GETTEXT_PACKAGE, ["moblin-panel-date-time"], [Package name for gettext])

GETTEXT_PACKAGE=moblin-panel-date-time
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE],
                   ["$GETTEXT_PACKAGE"],
                   [Gettext domain name])
AM_GLIB_GNU_GETTEXT


desktopentrydir=${datadir}/applications
AC_SUBST(desktopentrydir)

icondir=${datadir}/icons/hicolor/32x32/apps
AC_SUBST(icondir)

# Output files
AC_OUTPUT([Makefile
src/Makefile
data/Makefile
data/theme/Makefile
po/Makefile.in
])

echo ""
echo "   moblin-panel-date-time $VERSION"
echo "   ====================="
echo "   Documentation: ${enable_gtk_doc}"
echo ""
echo "   To build the project, run \"make\""
echo ""

