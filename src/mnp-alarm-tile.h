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

#ifndef _MNP_ALARM_TILE_H
#define _MNP_ALARM_TILE_H

#include <glib-object.h>
#include <mx/mx.h>

G_BEGIN_DECLS

#define MNP_TYPE_ALARM_TILE mnp_alarm_tile_get_type()

#define MNP_ALARM_TILE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  MNP_TYPE_ALARM_TILE, MnpAlarmTile))

#define MNP_ALARM_TILE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  MNP_TYPE_ALARM_TILE, MnpAlarmTileClass))

#define MNP_IS_ALARM_TILE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
  MNP_TYPE_ALARM_TILE))

#define MNP_IS_ALARM_TILE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
  MNP_TYPE_ALARM_TILE))

#define MNP_ALARM_TILE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  MNP_TYPE_ALARM_TILE, MnpAlarmTileClass))

typedef struct {
  MxButton parent;
} MnpAlarmTile;

typedef struct {
  MxButtonClass parent_class;
} MnpAlarmTileClass;

GType mnp_alarm_tile_get_type (void);

MnpAlarmTile* mnp_alarm_tile_new (void);

G_END_DECLS

#endif /* _MNP_ALARM_TILE_H */
