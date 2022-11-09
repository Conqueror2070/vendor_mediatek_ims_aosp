#ifndef __DP_NOTIFIER_WROT_H__
#define __DP_NOTIFIER_WROT_H__

#include "DpDataType.h"

typedef enum DP_SCENARIO_ENUM {
    DP_SCENARIO_NONE,
    DP_SCENARIO_VIDEO_NORMAL,
    DP_SCENARIO_CAMERA_PREVIEW,
    DP_SCENARIO_CAMERA_ZSD,
    DP_SCENARIO_CAMERA_CAPTURE,
    DP_SCENARIO_CAMERA_ICFP,
    DP_SCENARIO_VIDEO_SWDEC_PLAYBACK,
    DP_SCENARIO_VIDEO_PLAYBACK,
    DP_SCENARIO_VIDEO_PLAYBACK_HIGH_FPS,
    DP_SCENARIO_VIDEO_PLAYBACK_HIGH_RESOLUTION,
    DP_SCENARIO_VIDEO_TELEPHONY,
    DP_SCENARIO_VIDEO_RECORD,
    DP_SCENARIO_VIDEO_RECORD_CAMERA,
    DP_SCENARIO_VIDEO_RECORD_SLOWMOTION,
    DP_SCENARIO_VIDEO_SNAPSHOT,
    DP_SCENARIO_VIDEO_LIVE_PHOTO,
    DP_SCENARIO_VIDEO_WIFI_DISPLAY,
    DP_SCENARIO_FORCE_MMDVFS
} DP_SCENARIO_ENUM;

DP_STATUS_ENUM notifyScenario(DP_SCENARIO_ENUM scenario);

#endif  // __DP_NOTIFIER_WROT_H__
