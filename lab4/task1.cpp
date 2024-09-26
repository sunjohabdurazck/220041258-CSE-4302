#include <iostream>
#include <cmath>
using namespace std;

class TrigCalculator {
private:
    float value;

public:
    TrigCalculator() : value(0) {}
    TrigCalculator(float val) : value(val) {}

    float getValue() const {
        return value;
    }

    void setValue(float val) {
        value = val;
    }

    float calculateSine(float val) {
        value = sin(val);
        return value;
    }

    float calculateCosine(float val) {
        value = cos(val);
        return value;
    }

    float calculateTangent(float val) {
        value = tan(val);
        return value;
    }

    float calculateArcSine(float val) {
        if (val < -1 || val > 1) {
            cout << "Error: Input for arc sine must be between -1 and 1." << endl;
            return 0;
        }
        value = asin(val);
        return value;
    }

    float calculateArcCosine(float val) {
        if (val < -1 || val > 1) {
            cout << "Error: Input for arc cosine must be between -1 and 1." << endl;
            return 0;
        }
        value = acos(val);
        return value;
    }

    float calculateArcTangent(float val) {
        value = atan(val);
        return value;
    }

    void calculateForAngle(float paramAngle) {
        cout << "sin: " << calculateSine(paramAngle) << endl;
        cout << "cos: " << calculateCosine(paramAngle) << endl;
        cout << "tan: " << calculateTangent(paramAngle) << endl;
    }

    void clear() {
        value = 0;
    }

    void display() const {
        cout << "Calculator display: " << value << endl;
    }

    ~TrigCalculator() {
        cout << "Calculator object is destroyed." << endl;
    }
};

int main()
{
    TrigCalculator trig;
    trig.calculateForAngle(60);
   trig.calculateSine(60);
    trig.display();
    return 0;
}
