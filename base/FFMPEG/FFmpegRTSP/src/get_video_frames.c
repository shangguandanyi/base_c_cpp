#include <stdio.h>
#include <stdlib.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>

int main(int argc, char const *argv[])
{
	char *file_path = "../../100new.264";
	int video_stream_index = -1;
	int ret = 0;

	AVFormatContext *fmtCtx = NULL;
	AVPacket *pkt = NULL;
	AVCodecContext *codecCtx = NULL;
	AVCodecParameters *avCodecPara = NULL;
	const AVCodec *codec = NULL;

	fmtCtx = avformat_alloc_context();
	if ((ret = avformat_open_input(&fmtCtx, file_path, NULL, NULL) != 0))
	{
		printf("cannot open video file.\n");
	}

	if ((ret = avformat_find_stream_info(fmtCtx, NULL)) < 0)
	{
		printf("cannot retrive video info.\n");
	}

	for (size_t i = 0; i < fmtCtx->nb_streams; i++)
	{
		if (fmtCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			video_stream_index = i;
			break;
		}
	}

	if (video_stream_index == -1)
	{
		printf("cannot find video stream.\n");
	}

	av_dump_format(fmtCtx, 0, file_path, 0);

	// 查找解码器
	avCodecPara = fmtCtx->streams[video_stream_index]->codecpar;
	codec = avcodec_find_decoder(avCodecPara->codec_id);
	if (codec == NULL)
	{
		printf("cannot find decoder.\n");
	}
	
	// 根据解码器参数创建解码器内容
	codecCtx = avcodec_alloc_context3(codec);
	avcodec_parameters_to_context(codecCtx, avCodecPara);
	if (codecCtx == NULL)
	{
		printf("cannot alloc context.\n");
	}
	
	// 打开解码器
	if ((ret = avcodec_open2(codecCtx, codec, NULL)) < 0)
	{
		printf("cannot open decoder.\n");
	}
	
	// 分配AVPacket结构体
	int frame_index = 0;
	pkt = av_packet_alloc();
	av_new_packet(pkt, codecCtx->width * codecCtx->height);

	//读取视频信息
	while (av_read_frame(fmtCtx, pkt) >= 0)
	{
		if (pkt->stream_index == video_stream_index)
		{
			frame_index++;
		}
		av_packet_unref(pkt);
	}
	printf("Thera are total %d frames.\n", frame_index);

	av_packet_free(&pkt);
	avcodec_close(codecCtx);
	avformat_close_input(&fmtCtx);
	avformat_free_context(fmtCtx);

	return 0;
}
