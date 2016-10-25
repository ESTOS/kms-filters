/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef _KMS_MOVEMENT_DETECTOR_H_
#define _KMS_MOVEMENT_DETECTOR_H_

#include <gst/video/video.h>
#include <gst/video/gstvideofilter.h>
#include "opencv2/imgproc/imgproc_c.h"
#include <stdio.h>

G_BEGIN_DECLS
#define KMS_TYPE_MOVEMENT_DETECTOR   (kms_movement_detector_get_type())
#define KMS_MOVEMENT_DETECTOR(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_MOVEMENT_DETECTOR,KmsMovementDetector))
#define KMS_MOVEMENT_DETECTOR_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_MOVEMENT_DETECTOR,KmsMovementDetectorClass))
#define KMS_IS_MOVEMENT_DETECTOR(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_MOVEMENT_DETECTOR))
#define KMS_IS_MOVEMENT_DETECTOR_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_MOVEMENT_DETECTOR))
typedef struct _KmsMovementDetector KmsMovementDetector;
typedef struct _KmsMovementDetectorClass KmsMovementDetectorClass;

struct _KmsMovementDetector {
  GstVideoFilter parent;
  IplImage* img;
  IplImage* imgOldBW;
};

struct _KmsMovementDetectorClass {
  GstVideoFilterClass base_movementdetector_class;
};

GType kms_movement_detector_get_type (void);

gboolean kms_movement_detector_plugin_init (GstPlugin * plugin);

G_END_DECLS
#endif
