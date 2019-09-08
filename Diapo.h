#pragma once

#include <opencv2/core/mat.hpp>
#include <string>
#include <vector>

namespace lyonlib {

/*
 * Classe pour lire une à une les images d'un dossier
 * Exemple, faire défiler les images en appuyant sur le clavier :
 *
 *   lyonlib::Diapo my_diapo("directory/folder/", ".jpg");
 *   cv::Mat img;
 *   while (true) {
 *     my_diapo.read(img);
 *     cv::imshow("Img", img);
 *     cv::waitKey(0);
 *   }
 */
class Diapo {
 public:
  /*
   * @param foldername name of the folder where images are (ex: "data/images/")
   * @param extention type of images (ex: ".png")
   */
  Diapo(std::string foldername, std::string extention);

  /*
   * Récupère la prochaine image présente dans le dossier.
   * Si on arrive à la fin, le diapo recommence au début.
   *
   * @param image the frame is returned here. If no frames has been grabbed the image will be empty.
   * @return `false` if no frames has been grabbed
   */
  bool GrabFrame(cv::OutputArray image);

  /*
   * Récupère la prochaine image présente dans le dossier.
   * Si on arrive à la fin, le diapo recommence au début.
   *
   * @param image the frame is returned here. If no frames has been grabbed the image will be empty.
   * @return `false` if no frames has been grabbed
   */
  bool read(cv::OutputArray image);

 private:
  /*
   * Incrémente le compteur et retourne à zéro si il a atteint le nombre d'images
   */
  void incrementation();

  /*
   * Vérifie (et corrige) si le chemin se termine par "/"
   */
  std::string checkFolderName(std::string foldername);

  /*
   * Vérifie (et corrige) si l'extension commence par "."
   */
  std::string checkExtension(std::string extention);

  std::vector<cv::String> m_imagesNames;

  int m_nombreDePhotos;
  int m_iterator;
};

}  // namespace lyonlib
