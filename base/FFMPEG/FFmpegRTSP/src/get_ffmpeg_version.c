#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavutil/ffversion.h>

int main(int argc, char const *argv[])
{
	unsigned codecVer = avcodec_version();
	printf("FFmpeg version is: %s, avcodec version is: %d\n.",FFMPEG_VERSION,codecVer);
	return 0;
}
