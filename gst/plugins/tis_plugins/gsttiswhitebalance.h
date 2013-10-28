/* GStreamer
 * Copyright (C) 2013 Edgar Thier <edgarthier@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef _GST_TISWHITEBALANCE_H_
#define _GST_TISWHITEBALANCE_H_

#include <gst/base/gstbasetransform.h>
#include "bayer.h"


G_BEGIN_DECLS

#define GST_TYPE_TISWHITEBALANCE   (gst_tiswhitebalance_get_type())
#define GST_TISWHITEBALANCE(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_TISWHITEBALANCE,GstTisWhiteBalance))
#define GST_TISWHITEBALANCE_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_TISWHITEBALANCE,GstTisWhiteBalanceClass))
#define GST_IS_TISWHITEBALANCE(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_TISWHITEBALANCE))
#define GST_IS_TISWHITEBALANCE_CLASS(obj)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_TISWHITEBALANCE))


static const guint MAX_STEPS = 20;
static const guint WB_IDENTITY = 64;
static const guint WB_MAX = 255;
static const guint BREAK_DIFF = 2;

const guint NEARGRAY_MIN_BRIGHTNESS      = 10;
const guint NEARGRAY_MAX_BRIGHTNESS      = 253;
const float NEARGRAY_MAX_COLOR_DEVIATION = 0.25f;
const float NEARGRAY_REQUIRED_AMOUNT     = 0.08f;

/* rgb values have to be evaluated differently. These are the according factors */
static const guint r_factor = (guint32)((1 << 8) * 0.299f);
static const guint g_factor = (guint32)((1 << 8) * 0.587f);
static const guint b_factor = (guint32)((1 << 8) * 0.114f);

typedef unsigned char byte;

typedef struct
{
    GstBaseTransform base_tiswhitebalance;

    GstPad *sinkpad;
    GstPad *srcpad;

    /* user defined values */
    gint red;
    gint green;
    gint blue;

    tBY8Pattern pattern;

    /* persistent values */
    rgb_tripel rgb;

    gint height;
    gint width;

    gboolean auto_wb;
    gboolean auto_enabled;
} GstTisWhiteBalance;

typedef struct
{
    GstBaseTransformClass base_tiswhitebalance_class;
} GstTisWhiteBalanceClass;

GType gst_tiswhitebalance_get_type (void);

G_END_DECLS

#endif