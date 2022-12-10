#include <iostream>
#include <csignal>
#include <opencv2/opencv.hpp>

bool is_running = true;

void OnSignal(int) {
  is_running = false;
}

int main() {
  // 触发下面的信号就退出
  signal(SIGINT, OnSignal);
  signal(SIGQUIT, OnSignal);
  signal(SIGTERM, OnSignal);

  // 打开摄像头
  cv::VideoCapture capture("rtsp://admin:HQ123456789@192.168.4.12:554");
  if (!capture.isOpened()) {
    std::cerr << "Failed to open camera." << std::endl;
    return EXIT_FAILURE;
  }
  capture.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
  capture.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);

  std::string rtmp_server_url = "rtmp://192.168.4.7:1935/test";

  std::stringstream command;
  command << "ffmpeg ";

  // infile options
  command << "-y "  // overwrite output files
          << "-an " // disable audio
          << "-f rawvideo " // force format to rawvideo
          << "-vcodec rawvideo "  // force video rawvideo ('copy' to copy stream)
          << "-pix_fmt bgr24 "  // set pixel format to bgr24
          << "-s 1920x1080 "  // set frame size (WxH or abbreviation)
          << "-r 25 "; // set frame rate (Hz value, fraction or abbreviation)

  command << "-i - "; //

  // outfile options
  command << "-c:v libx264 "  // Hyper fast Audio and Video encoder
          << "-pix_fmt yuv420p "  // set pixel format to yuv420p
          << "-preset ultrafast " // set the libx264 encoding preset to ultrafast
          << "-f flv " // force format to flv
          << rtmp_server_url;

  cv::Mat frame;

  // 在子进程中调用 ffmpeg 进行推流
  FILE *fp = nullptr;
  fp = popen(command.str().c_str(), "w");

  // 将 cv 读到的每一帧传入子进程
  if (fp != nullptr) {
    while (is_running) {
      capture >> frame;
      if (frame.empty()) {
        continue;
      }

      fwrite(frame.data, sizeof(char), frame.total() * frame.elemSize(), fp);
    }
    pclose(fp);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}