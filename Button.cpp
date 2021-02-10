//
// Created by drlim on 09/02/2021.
//

#include "Button.h"

Button::Button(std::chrono::microseconds debounceDelay, bool polarity) : polarity(polarity),
                                                                         debounceDelay(debounceDelay) {}

bool Button::debounce(bool isPinHigh, std::chrono::microseconds runtime) {
    if (!polarity) {
        isPinHigh = !isPinHigh;
    }

    if (isPinHigh != lastButtonState) {
        lastDebounceTime = runtime;
        lastButtonState = isPinHigh;
    }

    if ((runtime - lastDebounceTime) > debounceDelay) {
        return true;
    } else {
        return false;
    }
}

bool Button::checkIfPressed(bool isPinHigh, std::chrono::microseconds runtime) {
    bool output = false;

    if (debounce(isPinHigh, runtime)) {
        if (isPinHigh != buttonState) {
            buttonState = isPinHigh;
            if (buttonState) {
                output = true;
            }
        }
    }

    return output;
}

std::chrono::microseconds Button::timePressed(bool isPinHigh, std::chrono::microseconds runtime) {
    if (debounce(isPinHigh, runtime)) {
         if (isPinHigh) {
            return runtime - lastDebounceTime;
        }
    }

    return 0s;
}
