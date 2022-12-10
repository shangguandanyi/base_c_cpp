# output
./video_decoder ../100new.264 output.yuv
ffplay -f rawvideo -pix_fmt yuv420p -video_size 1920*1080 output.yuv

./video_encoder ../output.yuv output.h264 libx264
ffplay -i output.h264