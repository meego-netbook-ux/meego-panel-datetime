/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */

/*
 * Copyright (C) 2010 Intel Corporation.
 *
 * Author: Srinivasa Ragavan <srini@linux.intel.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <locale.h>
#include <string.h>

#include <glib/gi18n.h>

#include <clutter/clutter.h>
#include <clutter/x11/clutter-x11.h>
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#include <moblin-panel/mpl-panel-clutter.h>
#include <moblin-panel/mpl-panel-common.h>
#include <moblin-panel/mpl-entry.h>

#include "mnp-datetime.h"

#define WIDGET_SPACING 5
#define ICON_SIZE 48
#define PADDING 8
#define N_COLS 4
#define LAUNCHER_WIDTH  235
#define LAUNCHER_HEIGHT 64

#include <config.h>

static void
_client_set_size_cb (MplPanelClient *client,
                     guint           width,
                     guint           height,
                     gpointer        userdata)
{
  g_debug (G_STRLOC ": %d %d", width, height);
  clutter_actor_set_size ((ClutterActor *)userdata,
                          width,
                          height);
}

static gboolean standalone = FALSE;

static GOptionEntry entries[] = {
  {"standalone", 's', 0, G_OPTION_ARG_NONE, &standalone, "Do not embed into the mutter-moblin panel", NULL},
  { NULL }
};

int
main (int    argc,
      char **argv)
{
  MplPanelClient *client;
  ClutterActor *stage;
  ClutterActor *datetime;
  GOptionContext *context;
  GError *error = NULL;
  ClutterActor *box, *label;

  setlocale (LC_ALL, "");
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  context = g_option_context_new ("- mutter-moblin date/time panel");
  g_option_context_add_main_entries (context, entries, GETTEXT_PACKAGE);
  g_option_context_add_group (context, clutter_get_option_group_without_init ());
  g_option_context_add_group (context, gtk_get_option_group (FALSE));
  if (!g_option_context_parse (context, &argc, &argv, &error))
  {
    g_critical (G_STRLOC ": Error parsing option: %s", error->message);
    g_clear_error (&error);
  }

  g_option_context_free (context);

  MPL_PANEL_CLUTTER_INIT_WITH_GTK (&argc, &argv);

  mx_style_load_from_file (mx_style_get_default (),
                           THEMEDIR "/date-panel.css", NULL);

  if (!standalone)
  {
    client = mpl_panel_clutter_new ("datetime",
                                    _("Date/Time"),
                                    NULL,
                                    "datetime-button",
                                    TRUE);

    MPL_PANEL_CLUTTER_SETUP_EVENTS_WITH_GTK (client);

    mpl_panel_client_set_height_request (client, 450);

    stage = mpl_panel_clutter_get_stage (MPL_PANEL_CLUTTER (client));
    datetime = mnp_datetime_new ();
    mnp_datetime_set_panel_client (MNP_DATETIME (datetime), client);
    g_signal_connect (client,
                      "set-size",
                      (GCallback)_client_set_size_cb,
                      datetime);
  } else {
    Window xwin;

    stage = clutter_stage_get_default ();
    clutter_actor_realize (stage);
    xwin = clutter_x11_get_stage_window (CLUTTER_STAGE (stage));

    MPL_PANEL_CLUTTER_SETUP_EVENTS_WITH_GTK_FOR_XID (xwin);
    datetime = mnp_datetime_new ();
    clutter_actor_set_size ((ClutterActor *)datetime, 1016, 405);
    clutter_actor_set_size (stage, 1016, 450);
    clutter_actor_show (stage);
  }

  box = mx_box_layout_new ();
  mx_box_layout_set_orientation ((MxBoxLayout *)box, MX_ORIENTATION_VERTICAL);

  label = mx_label_new ();
  clutter_actor_set_name (label, "DateHeading");
  mnp_date_time_set_date_label (datetime, label);

  mx_box_layout_add_actor (box, label, -1);
  mx_box_layout_add_actor (box, datetime, -1);

  clutter_actor_set_name ((ClutterActor *)box, "datetime-panel");

  clutter_container_add_actor (CLUTTER_CONTAINER (stage),
                               (ClutterActor *)box);


  clutter_main ();

  return 0;
}

