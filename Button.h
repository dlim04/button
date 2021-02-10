//
// Created by drlim on 09/02/2021.
//

#ifndef BUTTON_BUTTON_H
#define BUTTON_BUTTON_H


#include <chrono>

using namespace std::chrono_literals;

/**
 * A button that provides a method that allows whether the button is pressed or not to be checked. Also provides
 * software debouncing and allows checking of how long the button has been held for.
 * @author - David Lim
 */
class Button {
public:
    /**
     * Constructor for the Button object.
     * @param debounceDelay - The the desired delay for the debounce (to reduce interference) as a std::chrono::duration
     * @param polarity - The polarity of the button as a boolean value (true if when pressed input is high, false if
     *                   when pressed input is low)
     */
    explicit Button(std::chrono::microseconds debounceDelay = 50ms, bool polarity = true);

    /**
     * Check whether the button has been pressed.
     * @param isPinHigh - The input of the pin the button is connected to as a boolean value
     * @param runtime - The time the program has been running for as a std::chrono::duration
     * @return - Whether the button has been pressed as a boolean
     */
    bool checkIfPressed(bool isPinHigh, std::chrono::microseconds runtime);

    /**
     * Check how long the button has been pressed for.
     * @param isPinHigh - The input of the pin the button is connected to as a boolean value
     * @param runtime - The time the program has been running for as a std::chrono::duration
     * @return - The time the button has been pressed for as a std::chrono::duration (0 if button is not pressed)
     */
    std::chrono::microseconds timePressed(bool isPinHigh, std::chrono::microseconds runtime);

private:
    std::chrono::microseconds lastDebounceTime = 0s;
    std::chrono::microseconds debounceDelay;
    bool polarity;
    bool buttonState = false;
    bool lastButtonState = false;

    /**
     * Debounce the button input.
     *
     * Created by avid A. Mellis
     * Modified by Limor Fried 30/08/2011
     * Modified by Mike Walters 28/12/2012
     * Modified by Arturo Guadalupi 30/08/2016
     * Modified by David Lim 09/02/2021
     *
     * http://www.arduino.cc/en/Tutorial/Debounce
     * https://github.com/drlim2u/button
     *
     * @param isPinHigh - The input of the pin the button is connected to as a boolean value
     * @param runtime - The time the program has been running for as a std::chrono::duration
     * @return - If the pin reading has been there for longer than the debounce delay as a boolean
     */
    bool debounce(bool isPinHigh, std::chrono::microseconds runtime);
};


#endif //BUTTON_BUTTON_H
