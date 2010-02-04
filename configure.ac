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

AC_INIT(moblin_panel_date_time, moblin_panel_date_time_version)
AM_INIT_AUTOMAKE(moblin_panel_date_time, moblin_panel_date_time_version)
AC_CONFIG_HEADERS(config.h)
#AC_CONFIG_SRCDIR(libmoblin_panel_date_time/moblin_panel_date_time.cpp)

# Check for programs
AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_INSTALL

# enable pkg-config
PKG_PROG_PKG_CONFIG

# Check for function availability
# AC_CHECK_FUNCS([memset])

# all libraries listed are associated with "MOBLIN_PANEL_DATE_TIME" tag
PKG_CHECK_MODULES(MOBLIN_PANEL_DATE_TIME, glib-2.0
			clutter-1.0)

AC_SUBST(MOBLIN_PANEL_DATE_TIME_CFLAGS)
AC_SUBST(MOBLIN_PANEL_DATE_TIME_LIBS)



# i18n
ALL_LINGUAS="en_US"
AC_SUBST(ALL_LINGUAS)
AM_GLIB_GNU_GETTEXT
AC_DEFINE(GETTEXT_PACKAGE, ["moblin_panel_date_time"], [Package name for gettext])


desktopentrydir=${datadir}/applications
AC_SUBST(desktopentrydir)

icondir=${datadir}/icons/hicolor/32x32/apps
AC_SUBST(icondir)

# Output files
AC_OUTPUT([Makefile
src/Makefile
src/moblin_panel_date_time.desktop
])

echo ""
echo "   moblin-panel-date-time $VERSION"
echo "   ====================="
echo "   Documentation: ${enable_gtk_doc}"
echo ""
echo "   To build the project, run \"make\""
echo ""

