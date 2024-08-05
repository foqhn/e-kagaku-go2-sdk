#include <unitree/robot/go2/sport/sport_client.hpp>

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

    /*
     * Set request timeout 1.0s
     */
    sc.SetTimeout(10.0f);
    sc.Init();
    int32_t ret=sc.StopMove();
    std::cout << "Initialized" << ret << std::endl;

    //Test Api
    while (true)
    {
      //kayboard input
      char c;
      std::cout << "Press 'w' to move forward, 's' to move backward, 'a' to move left, 'd' to move right, 'q' to turn left, 'e' to turn right, 'x' to stop: " << std::endl;
      std::cin >> c;

      if (c == 'w')
      {
        int32_t ret=sc.Move(0.5f, 0.0f, 0.0f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      if (c == 's')
      {
        int32_t ret=sc.Move(-0.5f, 0.0f, 0.0f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      if (c == 'a')
      {
        int32_t ret=sc.Move(0.0f, 0.5f, 0.0f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      if (c == 'd')
      {
        int32_t ret=sc.Move(0.0f, -0.5f, 0.0f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      if (c == 'q')
      {
        int32_t ret=sc.Move(0.0f, 0.0f, 0.5f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      if (c == 'e')
      {
        int32_t ret=sc.Move(0.0f, 0.0f, -0.5f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      if (c == 'x')
      {
        int32_t ret=sc.Move(0.0f, 0.0f, 0.0f);
        std::cout << "Call sc.Move ret:" << ret << std::endl;
        usleep(1000);
      }

      // sit down by pressing 'c'
      if (c == 'c')
      {
        int32_t ret=sc.StandDown();
      
      }

      // stand up by pressing 'v'
      if (c == 'v')
      {
        int32_t ret=sc.StandUp();
      }

      // say hello by pressing 'h'
      if (c == 'h')
      {
        int32_t ret=sc.Hello();
        std::cout << "Call sc.Hello ret:" << ret << std::endl;
        usleep(1000);
      }

      // stop moving by pressing 'z'
      if (c == 'z')
      {
        int32_t ret=sc.StopMove();
        std::cout << "Call sc.StopMove ret:" << ret << std::endl;
        usleep(1000);
      }


    }

    return 0;
}