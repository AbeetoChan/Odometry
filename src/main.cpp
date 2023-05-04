#include "vex.h"
#include "odom.h"

vex::brain Brain;

Odometry Odom = Odometry(
    vex::rotation(3), // left rotation
    vex::rotation(5), // right rotation
    vex::rotation(7), // horizontal rotation
    Odometry::OdomResult(), // initial starting position (default)
    3.25 * M_PI, // wheel circumference
    0.6, // gear ratio
    10 // wheelbase
);

int main() {
    while (true) {
        Odom.Tick();
        auto result = Odom.GetOdomResult();

        Brain.Screen.clearScreen();
        Brain.Screen.printAt(10, 10, "Position: %f, %f", result.position.x, result.position.y);
        Brain.Screen.printAt(10, 20, "Rotation (radians): %f", result.angle);

        vex::wait(20, vex::timeUnits::msec);
    }
}