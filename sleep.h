#include <chrono>
#include <thread>
#include <stdexcept>

// void sleep (float seconds) 
//     {
        
//         std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));
//     }
// void sleep (double seconds) 
//     {
        
//         std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));
//     }
// void sleep (int seconds) 
//     {
        
//         std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));
//     }

/*Pauses the script for the given time in seconds. (int, double, float)
If there is an error, please make sure that the C++ debugger
and C++ version you are using supports "Templates". If not,
use the code above this code and delete it.*/
template <typename T> 
void sleep( T seconds )
    {
        if (seconds > 0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));
        }else{
            throw std::runtime_error("You can just use positive numbers. (Used number zero or negative number in sleep() function)");
        };

    }