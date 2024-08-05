#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unitree/robot/go2/video/video_client.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include <time.h>


//SnapImage function
//  Input: video_client object, image_name
//  Return: None
void SnapImage(unitree::robot::go2::VideoClient &video_client, std::string image_name){
  std::vector<uint8_t> image_sample;
  int ret;
  ret = video_client.GetImageSample(image_sample);

        if (ret == 0) {
            time_t rawtime;
            struct tm *timeinfo;
            char buffer[80];

            std::ofstream image_file(image_name, std::ios::binary);
            if (image_file.is_open()) {
                image_file.write(reinterpret_cast<const char*>(image_sample.data()), image_sample.size());
                image_file.close();
                std::cout << "Image saved successfully as " << image_name << std::endl;
            } else {
                std::cerr << "Error: Failed to save image." << std::endl;
            }


        }

        sleep(3);
}


int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    unitree::robot::go2::SportClient sc;
    unitree::robot::go2::VideoClient vc;

    /*
     * Set request timeout 1.0s
     */
    
    //Initialize the robot///////////////////////////
    sc.SetTimeout(1.0f);
    sc.Init();
    vc.SetTimeout(1.0f);
    vc.Init();


    int32_t ret=sc.StandUp();
    ret=sc.StopMove();
    usleep(1000);

    time_t start, end;
  
    /////////////////////////////////////////////////
    //MAIN CODE
    start = time(NULL);
    while(difftime(time(NULL), start) < 2.1){
        ret=sc.Move(0.5, 0.0, 0.0);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
    }

    start = time(NULL);
    while(difftime(time(NULL), start) < 1.2){
        ret=sc.Move(0.0, 0.0, -1.0);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
    }

    start = time(NULL);
    while(difftime(time(NULL), start) < 1.2){
        ret=sc.Move(0.5, 0.0, 0.0);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
    }

    SnapImage(vc, "image2.jpg");
    
  
    

    /////////////////////////////////////////////////
    ret=sc.StopMove();
    std::cout << "Call sc.Move ret:" << ret << std::endl;
    sleep(1);
    ret=sc.StandDown();
    usleep(1000);


    std::cout << "End of the program" << std::endl;

    return 0;
}