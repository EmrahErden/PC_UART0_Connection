// g++ PC_Code.cpp -o PC_Code -L/usr/lib -lserial
// sudo ./PC_Code

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
    my_serial_stream.SetParity( SerialStreamBuf::PARITY_NONE);
    my_serial_stream.Open("/dev/ttyACM0");  //opening the port
    if(!my_serial_stream.good())
    {
        std::cerr << "[" << __LINE__ << "]" << " , Port open error." << "\n";
    }

    my_serial_stream.SetBaudRate(SerialStreamBuf::BAUD_57600);
    if(!my_serial_stream.good())
    {
        std::cerr << "[" << __LINE__ << "]" << " , Baudrade error." << "\n";
    }
   
    while(1)
    {
    	  my_serial_stream << 'j';
    }
}
