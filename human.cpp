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

Human::Human(HumanMaker& maker) : maker_(&maker) {
}

float Human::age() {
    return maker_->age_;
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

Human* HumanMaker::born(Gender gender) {
    gender_ = gender;
    return new Human(*this);
}

HumanMaker& HumanMaker::setAge(float age) {
    age_ = age;
    return *this;
}

HumanMaker& HumanMaker::setHeight(float height) {
    height_ = height;
    return *this;
}

HumanMaker& HumanMaker::setWeight(float weight) {
    weight_ = weight;
    return *this;
}

HumanMaker& HumanMaker::setAlive(bool alive) {
    alive = alive_;
    return *this;
}