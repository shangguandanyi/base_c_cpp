#ifndef	VIDEO_ENCODER_CORE_H
#define VIDEO_ENCODER_CORE_H
#include <stdint.h>
#include "io_data.h"

int32_t init_video_encoder(const char* codec_name);
void destroy_video_encoder();
int32_t encoding(int32_t frame_cnt);

#endif