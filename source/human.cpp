/*
Copyright ©2024-2034 by Dzher. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), 
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "human.h"

#include <ctime>

Human::Human(HumanMaker& maker) : maker_(&maker) {
}

float Human::age() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int current_year = ltm->tm_year + 1900;
    int current_month = ltm->tm_mon + 1;
    int current_day = ltm->tm_mday;

    int age_months = (current_year * 12 + current_month) - (maker_->birth_day_.year * 12 + maker_->birth_day_.month);

    return static_cast<float>(age_months) / 12.f;
}

float Human::height() {
    return maker_->height_;
}

float Human::weight() {
    return maker_->weight_;
}

bool Human::alive() {
    return maker_->alive_;
}

bool Human::grown() {
    return maker_->grown_;
}

Gender Human::gender() {
    return maker_->gender_;
}

Human* HumanMaker::born(Date birth_day, Gender gender) {
    birth_day_ = birth_day;
    gender_ = gender;
    if (Gender::None == gender_) {
        alive_ = false;
    }

    if (alive_) {
        return new Human(*this);
    }
    return nullptr;
}

HumanMaker& HumanMaker::setHeight(float height) {
    height_ = height;
    if (height_ < 25.0 || height_ > 65.0) {
        alive_ = false;
    }
    return *this;
}

HumanMaker& HumanMaker::setWeight(float weight) {
    weight_ = weight;
    if (weight_ < 2.0 || weight_ > 5.0) {
        alive_ = false;
    }
    return *this;
}

HumanMaker& HumanMaker::setAlive(bool alive) {
    alive = alive_;
    return *this;
}