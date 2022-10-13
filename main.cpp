#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

// Load a cropped text line image
// you can find cropped images for testing in "Images for Testing"

int rgb = 0; // This should be changed according to the model input requirement.


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s [imagepath]\n", argv[0]);
        return -1;
    }

    const char* imagepath = argv[1];

    cv::Mat frame = cv::imread(imagepath, rgb);
    if (frame.empty())
    {
        fprintf(stderr, "cv::imread %s failed\n", imagepath);
        return -1;
    }

    // Load models weights
    cv::dnn::TextRecognitionModel model("DenseNet_CTC.onnx");
    // The decoding method
    // more methods will be supported in future
    model.setDecodeType("CTC-greedy");
    // Load vocabulary
    // vocabulary should be changed according to the text recognition model
    std::ifstream vocFile;
    vocFile.open("alphabet_36.txt");
    CV_Assert(vocFile.is_open());
    String vocLine;
    std::vector<String> vocabulary;
    while (std::getline(vocFile, vocLine)) {
        vocabulary.push_back(vocLine);
    }
    model.setVocabulary(vocabulary);

    // Normalization parameters
    double scale = 1.0 / 127.5;
    Scalar mean = Scalar(127.5, 127.5, 127.5);
    // The input shape for the model.
    // NOT the size of the input image.
    Size inputSize = Size(100, 32);
    model.setInputParams(scale, inputSize, mean);

    std::string recognitionResult;
   chrono::steady_clock::time_point Tbegin, Tend;

Tbegin = chrono::steady_clock::now();

for(int i=0;i<50;i++)    {
    recognitionResult = model.recognize(frame);
}

Tend = chrono::steady_clock::now();

float f = chrono::duration_cast <chrono::milliseconds> (Tend - Tbegin).count();

    std::cout << "FPS : " << 1000.0/(f/50)  << std::endl;


    std::cout << "'" << recognitionResult << "'" << std::endl;

    imshow("Text Detection", frame);
    waitKey();

    return 0;
}
