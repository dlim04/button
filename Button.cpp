//
// Created by drlim on 09/02/2021.
//

#include "Button.h"

Button::Button(std::chrono::microseconds debounceDelay, bool polarity) : polarity(polarity),
                                                                         debounceDelay(debounceDelay) {}

bool Button::debounce(bool isPinHigh, std::chrono::microseconds runTime) {
    if (!polarity) {
        isPinHigh = !isPinHigh;
    }

    if (isPinHigh != lastButtonState) {
        lastDebounceTime = runTime;
        lastButtonState = isPinHigh;
    }

    if ((runTime - lastDebounceTime) > debounceDelay) {
        return true;
    } else {
        return false;
    }
}

bool Button::checkIfPressed(bool isPinHigh, std::chrono::microseconds runTime) {
    bool output = false;

    if (debounce(isPinHigh, runTime)) {
        if (isPinHigh != buttonState) {
            buttonState = isPinHigh;
            if (buttonState) {
                output = true;
            }
        }
    }

    return output;
}

std::chrono::microseconds Button::timePressed(bool isPinHigh, std::chrono::microseconds runTime) {
    if (debounce(isPinHigh, runTime)) {
         if (isPinHigh) {
            return runTime - lastDebounceTime;
        }
    }

    return 0s;
}
