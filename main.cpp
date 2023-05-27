#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>
#include <sstream>

auto face_detection_algorithm = "haarcascade_frontalface_default.xml";

int main()
{
    cv::VideoCapture video(0);
    cv::CascadeClassifier facedetect;
    cv::Mat camera_image;
    facedetect.load(face_detection_algorithm);

    while (true)
    {
        video.read(camera_image);

        std::vector<cv::Rect> faces;

        facedetect.detectMultiScale(camera_image, faces, 1.3, 5);

        for (int i = 0; i < faces.size(); i++)
        {
            // Draw a rectangle around each detected face
            cv::rectangle(camera_image, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
            // Display number of faces found on the image
            cv::putText(camera_image, std::to_string(faces.size()) + " Face Found", cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);
        }
        // Display current frame with detected faces
        cv::imshow("Frame", camera_image);
        // 27 = Escape key
        if (cv::waitKey(1) == 27)
        {
            break;
        }
    }
    return 0;
}
