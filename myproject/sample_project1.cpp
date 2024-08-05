#include <unitree/robot/go2/sport/sport_client.hpp>
#include <time.h>


int main(int argc, char **argv)
{

    //network interface of the robot
   if (argc < 2)
   {
     std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
     exit(-1);
   }
   unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
   //argv [1]  is network interface of the robot
   unitree::robot::go2::SportClient sc;
   sc.SetTimeout(1.0f);


   //Initialize the robot///////////////////////////
   sc.Init();			//初期化
   int32_t ret=sc.StandUp();	//ロボットを立たせる
   ret=sc.StopMove();		//モーターの動作命令を止める。これをしないと歩けない
   usleep(1000);
   /////////////////////////////////////////////////


   //MAIN CODE//////////////////////////////////////
   ret=sc.Move(0.5, 0.0, 0.0);	//歩行させる関数　Move(ｘ方向速度(m/s),y方向速度(m/s),旋回速度(rad/s))
   std::cout << "Call sc.Move ret:" << ret << std::endl;
   sleep(1);
   /////////////////////////////////////////////////


   //Shutdown process///////////////////////////////
   ret=sc.StopMove();
   std::cout << "Call sc.Move ret:" << ret << std::endl;
   sleep(1);
   ret=sc.StandDown();		//座らせる
   usleep(1000);
    /////////////////////////////////////////////////



   std::cout << "End of the program" << std::endl;


   return 0;
}