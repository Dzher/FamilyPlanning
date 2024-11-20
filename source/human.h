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

enum class Gender
{
    None,
    Male,
    Female
};

struct Date
{
    int year;
    int month;
    int day;
};

class HumanMaker;
class Human
{
public:
    Date birthDay();
    float age();
    float height();
    float weight();
    bool alive();
    bool grown();
    Gender gender();

private:
    explicit Human(HumanMaker& maker);
    HumanMaker* maker_;

    friend class HumanMaker;
};

class HumanMaker
{
public:
    Human* born(Date birth_day, Gender gender);
    HumanMaker& setAge(float age);
    HumanMaker& setHeight(float height);
    HumanMaker& setWeight(float weight);
    HumanMaker& setAlive(bool alive);

private:
    Date birth_day_{};
    float height_ = 48.0;  // cm
    float weight_ = 2.80;  // kg
    bool grown_ = false;   // 18+
    bool alive_ = true;
    Gender gender_{Gender::None};  // Any serious country recognizes only two genders: male and female

    friend class Human;
};