#ifndef ODOM_H
#define ODOM_H

#include "vex.h"

class Odometry {
public:
    struct OdomResult {
        Vector2F position = Vector2F(0, 0);
        float angle = 0;
    };

    Odometry(
        vex::rotation leftRotation, 
        vex::rotation rightRotation,
        vex::rotation horizontalRotation, 
        OdomResult startPos,
        const float wheelCircumference,
        const float gearRatio,
        const float wheelBase
    )
        : m_LeftRotation(leftRotation), 
        m_RightRotation(rightRotation),
        m_HorizontalRotation(horizontalRotation),
        m_Result(startPos),
        c_InchesPerRev(wheelCircumference * gearRatio),
        c_WheelBase(wheelBase) {
    }

    OdomResult GetOdomResult() const {return m_Result;}

    void Tick();
private:
    const float c_InchesPerRev;
    const float c_WheelBase;

    vex::rotation m_LeftRotation;
    vex::rotation m_RightRotation;
    vex::rotation m_HorizontalRotation;

    OdomResult m_Result;

    float m_LastLeft = 0;
    float m_LastRight = 0;
    float m_LastHorizontal = 0;
};

#endif