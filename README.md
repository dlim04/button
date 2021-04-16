# button
A generic button class written in C++ with software debouncing

## Example
The following example was written for mbed-os v6.7:
```C++
#include "mbed.h"
#include "Button.h"

static BufferedSerial serial_port(USBTX, USBRX, 9600);

int main() {
    DigitalIn buttonPin(p7);
    DigitalOut led(LED1);
    
    bool isOn = false;
    
    Timer runtime;
    runtime.start();
    
    Button button;
    while (true) {
        if (button.isPressed(buttonPin.read(), runtime.elapsed_time())) {
            isOn = !isOn;
            led.write(isOn);
        }
        int timePressed = duration_cast<std::chrono::milliseconds>(
                button.timePressed(buttonPin.read(), runtime.elapsed_time())).count();
        printf("Time pressed: %dms\r\n", timePressed);
    }
}

```
