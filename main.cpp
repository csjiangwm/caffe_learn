/*             ,%%%%%%%%, 
 *           ,%%/\%%%%/\%% 
 *          ,%%%\c "" J/%%% 
 * %.       %%%%/ o  o \%%% 
 * `%%.     %%%%    _  |%%% 
 *  `%%     `%%%%(__Y__)%%' 
 *  //       ;%%%%`\-/%%%'
 * ((       /  `%%%%%%%' 
 *  \\    .'          | 
 *   \\  /       \  | | 
 *    \\/         ) | | 
 *     \         /_ | |__ 
 *     (___________))))))) 攻城湿 
 * 
 *        ___           __ ____   ____
 *       | | \   ____  / /| |\ \ | |\ \
 *       | |\ \ / / | / / | |\ \ | |\ \ 
 *       | | \ V /| |/ /  | |\ \| | \ \ 
 *     _ | |  \_/ |_|_/   |_|\_\|_| \_\ 
 *    \\ | |
       \ | |
        \_| 
        
   Created Time: 08 15th, 2018
   Revised Time: -------------
   Function: Create train.txt and test.txt for caffe training and testing
*/
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace cv;
using namespace cv::dnn;
using namespace std;

std::vector<string> readClassLabels(char* filename)
{
	std::vector<string> classNames;
	ifstream fp(filename);
	if (!fp.is_open())
	{
		std::cerr << "File with classes labels not found: " << filename << std::endl;
		exit(-1);
	}
	std::string name;
	while (!fp.eof())
	{
		std::getline(fp, name);
		if (name.length())
		{
			classNames.push_back(name.substr(name.find(' ') + 1));
		}
	}
	fp.close();
	return classNames;
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cerr << " Check your input parameters" << std::endl;
	}
	string modelTxt = argv[1];
	string modelBin = argv[2];
	string imageName = argv[3];
	char* classFile = argv[4];
	Mat img = imread(imageName);
	if (img.empty())
	{
		std::cerr << "Connot read image:" << argv[3] << std::endl;
	}
	Net net = dnn::readNetFromCaffe(modelTxt,modelBin);
	if (net.empty())
	{
		std::cerr << "Can't load network by using the following files: "<< std::endl;
		std::cerr << "prototxt: "<< modelTxt << std::endl;
		std::cerr << "caffemodel: "<< modelBin << std::endl;
		return-1;
	}
	std::vector<string> labels = readClassLabels(classFile);
	Mat inputBlob = blobFromImage(img, 1, Size(227, 227),Scalar(100, 114, 121));
	Mat prob;
	net.setInput(inputBlob, "data"); 
	prob = net.forward("prob"); 
	Mat probMat = prob.reshape(1, 1);
	Point classNumber;
	double classProb;
	minMaxLoc(probMat, NULL, &classProb, NULL, &classNumber); 
	int classIdx = classNumber.x; // 分类索引号
	printf("n current image classification : %s, possible : %.2f n", labels.at(classIdx).c_str(), classProb);
	putText(img, labels.at(classIdx), Point(20, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2, 8);
	imshow("Image Category", img);
	waitKey(0);
	return 0;
}