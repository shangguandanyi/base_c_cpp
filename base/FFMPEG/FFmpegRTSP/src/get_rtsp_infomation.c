/**
 * @file get_rtsp_infomation.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 输出RTSP视频信息
 */

#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

int main(int argc, char const *argv[])
{
	AVFormatContext *fmt_ctx = NULL; //创建对象并初始化
	const char *rtsp_url = "rtsp://admin:HQ123456789@192.168.4.13:554";
	int ret = 0;
	if ((ret = avformat_open_input(&fmt_ctx, rtsp_url, NULL, NULL)) < 0)
	{
		printf("fail to open url: %s, return value: %d\n", rtsp_url, ret);
	}

	if ((ret = avformat_find_stream_info(fmt_ctx, NULL)) < 0)
	{
		printf("failed to retrieve input stream information\n");
	}

	av_dump_format(fmt_ctx, 0, rtsp_url, 0);

	avformat_close_input(&fmt_ctx);//关闭文件

	return 0;
}