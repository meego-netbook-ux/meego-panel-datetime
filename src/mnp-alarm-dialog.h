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


#ifndef _MNP_ALARM_DIALOG_H
#define _MNP_ALARM_DIALOG_H

#include <glib-object.h>
#include <mx/mx.h>
#include "mnp-alarm-tile.h"

G_BEGIN_DECLS

#define MNP_TYPE_ALARM_DIALOG mnp_alarm_dialog_get_type()

#define MNP_ALARM_DIALOG(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  MNP_TYPE_ALARM_DIALOG, MnpAlarmDialog))

#define MNP_ALARM_DIALOG_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  MNP_TYPE_ALARM_DIALOG, MnpAlarmDialogClass))

#define MNP_IS_ALARM_DIALOG(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
  MNP_TYPE_ALARM_DIALOG))

#define MNP_IS_ALARM_DIALOG_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
  MNP_TYPE_ALARM_DIALOG))

#define MNP_ALARM_DIALOG_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  MNP_TYPE_ALARM_DIALOG, MnpAlarmDialogClass))

typedef struct {
  MxBoxLayout parent;
} MnpAlarmDialog;

typedef struct {
  MxBoxLayoutClass parent_class;
} MnpAlarmDialogClass;

GType mnp_alarm_dialog_get_type (void);

typedef enum {
	MNP_ALARM_NEVER=0,
	MNP_ALARM_EVERYDAY,
	MNP_ALARM_WORKWEEK, /* Mon-Fri*/
	MNP_ALARM_MONDAY,
	MNP_ALARM_TUESDAY,
	MNP_ALARM_WEDNESDAY,
	MNP_ALARM_THURSDAY,
	MNP_ALARM_FRIDAY,
	MNP_ALARM_SATURDAY,
	MNP_ALARM_SUNDAY
}MnpAlarmRecurrance;

typedef enum {
	MNP_SOUND_OFF=0,
	MNP_SOUND_BEEP,
	MNP_SOUND_MUSIC,
	MNP_SOUND_MESSAGE
}MnpAlarmSound;

MnpAlarmDialog* mnp_alarm_dialog_new (void);
void mnp_alarm_dialog_set_item (MnpAlarmDialog *dialog, MnpAlarmItem *item);
G_END_DECLS

#endif /* _MNP_ALARM_DIALOG_H */
