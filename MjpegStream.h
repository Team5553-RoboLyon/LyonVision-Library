#pragma once

#include <cscore.h>
#include <cscore_cv.h>

#include <opencv2/core/mat.hpp>
#include <string>

namespace lyonlib {

/*
 * Classe pour créer un stream video facilement
 * - Possibilité de connaître l'url du stream
 * - Un seul objet à créer
 */
class MjpegStream {
 public:
  /*
    @param name stream name
    @param width stream width
    @param height stream height
    @param fps stream fps
  */
  MjpegStream(const std::string name, int width, int height, int fps);

  /*
   * Put a new frame to the stream
   *
   * @param frame the image to be displayed
   */
  void PutFrame(cv::Mat &frame);

  /*
    Get stream url at the format: "mjpg:http://<hostname>.local:<port>/?action=stream"

    @return stream url
  */
  std::string GetStreamAddress();

 private:
  cs::CvSource    m_streamSrc;
  cs::MjpegServer m_streamServer;
};

}  // namespace lyonlib
