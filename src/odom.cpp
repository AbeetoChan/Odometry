#include "odom.h"

#include <math.h>

void Odometry::Tick() {
    float left = m_LeftRotation.position(vex::rotationUnits::rev);
    float right = m_RightRotation.position(vex::rotationUnits::rev);
    float horizontal = m_HorizontalRotation.position(vex::rotationUnits::rev);
    float deltaLeft = left - m_LastLeft;
    float deltaRight = right - m_LastRight;
    float deltaHorizontal = horizontal - m_LastHorizontal;
    m_LastLeft = left;
    m_LastRight = right;
    m_LastHorizontal = horizontal;

    float deltaTheta = c_InchesPerRev * (deltaRight - deltaLeft) / c_WheelBase;
    float deltaX = c_InchesPerRev * deltaHorizontal - deltaTheta * c_WheelBase / 2;
    float deltaY = c_InchesPerRev * (deltaLeft + deltaRight) / 2;

    float theta = m_Result.angle + deltaTheta / 2;
    m_Result.position.x += std::cos(theta) * deltaX - std::sin(theta) * deltaY;
    m_Result.position.y += std::sin(theta) * deltaX + std::cos(theta) * deltaY;
    m_Result.angle += deltaTheta;
}