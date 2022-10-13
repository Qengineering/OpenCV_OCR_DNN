# OpenCV_OCR_DNN
![output image]( https://qengineering.eu/github/OpenCV_OCR_1.png )
![output image]( https://qengineering.eu/github/OpenCV_OCR_2.png )
## Recognize text with deep learning on a bare Raspberry Pi 4. <br/>
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)<br/><br/>
Paper: https://arxiv.org/pdf/1507.05717.pdf<br/>
Special made for a bare Raspberry Pi 4, see [Q-engineering deep learning examples](https://qengineering.eu/deep-learning-examples-on-raspberry-32-64-os.html)

------------

## Dependencies.
To run the application, you have to:
- A raspberry Pi 4 with a 32 or 64-bit operating system. It can be the Raspberry 64-bit OS, or Ubuntu 18.04 / 20.04. [Install 64-bit OS](https://qengineering.eu/install-raspberry-64-os.html) <br/>
- OpenCV ***version 4.5.1 or higher*** 64-bit installed. [Install OpenCV 4.5](https://qengineering.eu/install-opencv-4.5-on-raspberry-64-os.html) <br/>
- Code::Blocks installed. (```$ sudo apt-get install codeblocks```)


------------

## Notes.
The image is resized to 100x32 pixels (line 56 at `main.cpp`) before being processed by OpenCV's deep learning engine.<br>
Obvious, your text must be one line and not too long to be recognized properly.<br>
In contrast to tesseract, deep learning models are less sensitive to font, colour, noise, scale, and skew.<br>
For more models, check the [OpenCV tutorial](https://docs.opencv.org/4.x/d4/d43/tutorial_dnn_text_spotting.html). Most consume considerably more computer power, hence more significant interference times.

------------

## Installing the app.
To extract and run the network in Code::Blocks <br/>
$ mkdir *MyDir* <br/>
$ cd *MyDir* <br/>
$ wget https://github.com/Qengineering/OpenCV_OCR_DNN/archive/refs/heads/main.zip <br/>
$ unzip -j master.zip <br/>
Remove master.zip, LICENSE and README.md as they are no longer needed. <br/> 
$ rm master.zip <br/>
$ rm LICENSE <br/>
$ rm README.md <br/> <br/>
Your *MyDir* folder must now look like this: <br/> 
*.png <br/>
alphabet_36.txt <br/>
alphabet_94.txt <br/>
OpenCV_OCR.cpb <br/>
main.cpp <br/>
DenseNet_CTC.onnx <br/>

------------

## Running the app.
To run the application load the project file OpenCV_OCR.cbp in Code::Blocks.<br/> 
Next, follow the instructions at [Hands-On](https://qengineering.eu/deep-learning-examples-on-raspberry-32-64-os.html#HandsOn).

------------

[![paypal](https://qengineering.eu/images/TipJarSmall4.png)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=CPZTM5BB3FCYL) 
