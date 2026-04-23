#include <Servo.h>
#include <math.h>

Servo servo1;
Servo servo2;


#define l0 1.875
#define l1 6.8734
#define l2 8.4692


void ik_5r(float x, float y, float &theta1, float &theta2)
{
  float e1 = x + l0;
  float e2 = l0 - x;

  float d1 = sqrt(e1 * e1 + y * y);
  float d2 = sqrt(e2 * e2 + y * y);

  float k1 = (l1 * l1 + d1 * d1 - l2 * l2) / (2 * l1 * d1);
  float k2 = (l1 * l1 + d2 * d2 - l2 * l2) / (2 * l1 * d2);

  k1 = constrain(k1, -1.0, 1.0);
  k2 = constrain(k2, -1.0, 1.0);

  float alpha1 = acos(k1);
  float alpha2 = acos(k2);

  float beta1 = atan2(y, e1);
  float beta2 = atan2(y, e2);

  theta1 = beta1 + alpha1;
  theta2 = PI - beta2 - alpha2;
}


void moveTo(float x, float y)
{
  float t1, t2;
  ik_5r(x, y, t1, t2);

  int deg1 = constrain(t1 * 180.0 / PI, 0, 180);
  int deg2 = constrain(t2 * 180.0 / PI, 0, 180);

  servo1.write(deg1);
  servo2.write(deg2);

  delay(30); 
}

void setup()
{
  servo1.attach(9);
  servo2.attach(10);
}


void drawLine(float x1, float y1, float x2, float y2)
{
  int steps = 40;

  for (int i = 0; i <= steps; i++)
  {
    float t = (float)i / steps;

    float x = x1 + t * (x2 - x1);
    float y = y1 + t * (y2 - y1);

    moveTo(x, y);
  }
}

void loop()
{
  float x1 = 2, y1 = 8;
  float x2 = 8, y2 = 8;
  float x3 = 8, y3 = 14;
  float x4 = 2, y4 = 14;

  // Draw square
  drawLine(x1, y1, x2, y2);
  drawLine(x2, y2, x3, y3);
  drawLine(x3, y3, x4, y4);
  drawLine(x4, y4, x1, y1);
}