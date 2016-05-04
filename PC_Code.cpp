#include <SerialStream.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>

using namespace LibSerial;
using namespace std;

int main(void)
{
    SerialStream my_serial_stream;
    my_serial_stream.Open("/dev/ttyACM0");  //opening the port
    if(!my_serial_stream.good())
    {
        std::cerr << "[" << __LINE__ << "]" << " , Port open error." << "\n";
    }

    my_serial_stream.SetBaudRate(SerialStreamBuf::BAUD_115200);
    if(!my_serial_stream.good())
    {
        std::cerr << "[" << __LINE__ << "]" << " , Baudrade error." << "\n";
    }
}
