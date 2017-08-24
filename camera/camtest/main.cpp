#include <ctime>
#include <fstream>
#include <iostream>
#include <wiringPi.h>
#include <raspicam/raspicam.h>
 
int main()
{
	    raspicam::RaspiCam Camera; //Cmaera object
		//Open camera 
		std::cout << "Opening Camera..." <<std::endl;
		if ( !Camera.open()) {
			std::cerr<< "Error opening camera" << std::endl; return -1;
		}
		//wait a while until camera stabilizes
		std::cout << "Sleeping for 3 secs" << std::endl;
		//capture
		Camera.grab();
		//allocate memory
		unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB )];
		//extract the image in rgb format
		Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_RGB );//get camera image
		//save
		std::ofstream outFile ( "raspicam_image.ppm",std::ios::binary );
		outFile << "P6\n"<<Camera.getWidth() << " " << Camera.getHeight() << " 255\n";
		outFile.write ( ( char* ) data, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB ) );
		std::cout << "Image saved at raspicam_image.ppm" << std::endl;
		//free resrources    
		delete data;
		return 0;
}
