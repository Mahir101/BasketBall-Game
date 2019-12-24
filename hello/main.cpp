#include<GL/glut.h >
#include<bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<string>
using namespace std;

int score=0, level=2, X_level=0, attempts;
double angle, velocity;
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
char *message;
int temp = attempts;
void output(int x, int y, char *string)  /// window te print korar jonne times new roman font
{
    int len;
    glRasterPos2f(x, y); //bitmap er positioning er jonne lage
    len = (int) strlen(string);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}
void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 210.0, 0.0, 200.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    while (attempts!=-1)
    {
        int flag = 0;  ///IF Ball hits the ceiling
        int flag1 = 0; ///IF Ball hits the Rim and Falls on the ground
        int flag2 = 0; ///IF Ball hits The Pole
        int flag3 = 0; ///IF Ball goes into the Basket

        ///*------Different co-ordinates for Ball*///

        int Y_BallHitsCeiling = 0, RelativeX_BallHitsPole = 1,RelativeX_BallHitsRim = 1;
        double X_BallHitsCeiling, X_BallHitsRim, Y_BallHitsRim, X_BallInBasket, Y_BallInBasket, X_BallHitsPole, Y_BallHitsPole;

        float theta = ((3.1415926f)/180)*(angle);
        double dist_x = 100, dist_y = 100, r = 5;       /// Center Coordinates and Radius Of the BasketBall

        for (double time = 0; time < 600; time++)
        {
            /// Number of Iterations For Trajectory OF the Ball
            glClear(GL_COLOR_BUFFER_BIT);

            ///*--------Background---------*///
            //   if(time <50)
            //  {


            glBegin(GL_POLYGON);
            glColor3f( 0.0f, 0.3f, 0.3f);
            glVertex2f(0.0, 0.0);
            glVertex2f(210.0, 0.0);

            glVertex2f(210.0, 0.0);
            glVertex2f(210.0, 90.0);

            glVertex2f(210.0, 90.0);
            glVertex2f(0.0, 90.0);

            glVertex2f(0.0, 90.0);
            glVertex2f(0.0, 0.0);
            glEnd();
            //   }

            glBegin(GL_POLYGON);
            glColor3f( 0.0f, 0.45f, 0.45f);
            glVertex2f(0.0, 90.0);
            glVertex2f(210.0, 90.0);

            glVertex2f(210.0, 90.0);
            glVertex2f(210.0, 500.0);

            glVertex2f(210.0, 500.0);
            glVertex2f(0.0, 500.0);

            glVertex2f(0.0, 500.0);
            glVertex2f(0.0, 90.0);
            glEnd();
            //wall er ta

            ///*--------Basketball Court---------*///

            glBegin(GL_POLYGON);
            glColor3f( 0.137255f, 0.137255f, 0.556863f);
            glVertex2f(0.0, 25.0);
            glVertex2f(203.0, 25.0);

            glVertex2f(203.0, 25.0);
            glVertex2f(210.0, 80.0);

            glVertex2f(210.0, 80.0);
            glVertex2f(15.0, 80.0);

            glVertex2f(0.0, 25.0);
            glVertex2f(15.0, 80.0);
            glEnd();

            //Display er lekha gula

            glColor3f(0.85f, 0.85f, 0.1f);
            output(10,190,"Attempts Left :");
            glColor3f(0.85f, 0.85f, 0.1f);
            char buffer[33],buffer1[33],buffer2[33];
            itoa (attempts,buffer,10);
            output(73,190,buffer);

            glColor3f(0.85f, 0.85f, 0.1f);
            output(10,170,"Your Score :");
            glColor3f(0.85f, 0.85f, 0.1f);
            itoa (score,buffer1,10);
            output(73,170,buffer1);


            //Court Boundary
            //Court Boundary gula GL_Lines parameter pass kore easily toiri kora jai :D


            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(0.0, 25.0);
            glVertex2f(203.0, 25.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(0.0, 28.0);
            glVertex2f(203.0, 28.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(203.0, 25.0);
            glVertex2f(210.0, 80.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(197.0, 25.0);
            glVertex2f(204.0, 80.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(210.0, 80.0);
            glVertex2f(15.0, 80.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(210.0, 77.0);
            glVertex2f(15.0, 77.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(0.0, 25.0);
            glVertex2f(15.0, 80.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(6.0, 25.0);
            glVertex2f(21.0, 80.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.85f, 0.85f, 0.1f);
            glVertex2f(105.0, 25.0);
            glVertex2f(115.0, 80.0);
            glEnd();

            ///*--------Basketball Ring---------*///

            /// The Circumference of Ring

            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            float dist_x1 = 175.0, dist_y1 = 165.0, r1 = 7.5, num_segments = 1000;
            float alpha = 2 * 3.1415926 / float(num_segments);
            float c = cosf(alpha); ///pre calculate the sine and cosine
            float s = sinf(alpha);
            float t;
            float x = r1;          ///we start at angle = 0
            float y = 0;

            glBegin(GL_POLYGON);
            glColor3f(0.0f, 0.0f, 0.0f);
            for (int ii = 0; ii < num_segments; ii++)
            {
                glVertex2f(2 * x + dist_x1, (0.5) * y + dist_y1); ///output vertex
                ///apply the rotation matrix
                t = x;
                x = c * x - s * y;
                y = s * t + c * y;
            }
            glEnd();


            ///Basket Net

            alpha = 2 * 3.1415926 / float(40);
            c = cosf(alpha); ///pre calculate the sine and cosine
            s = sinf(alpha);
            for (int ii = 0; ii < num_segments; ii++)
            {
                glBegin(GL_LINES);
                glColor3f(0.90f,  0.91f, 0.98f);
                glVertex2f(2 * x + dist_x1, (0.5) * y + dist_y1); ///output vertex
                glVertex2f(2 * x + dist_x1, (0.5) * y + dist_y1-9); ///output vertex

                glBegin(GL_LINES);
                glColor3f(0.90f,  0.91f, 0.98f);
                glVertex2f(2 * x + dist_x1, (0.5) * y + dist_y1); ///output vertex
                glVertex2f(2 * c * x - s * y  + dist_x1, (0.5) * y + dist_y1-9); ///output vertex
                //apply the rotation matrix
                t = x;
                x = c * x - s * y ;
                y = s * t + c * y;
            }
            glEnd();

            ///making the boundary of circumference thicker

            alpha = 2 * 3.1415926 / float(num_segments);
            c = cosf(alpha); ///pre calculate the sine and cosine
            s = sinf(alpha);
            for (int ii = 0; ii < num_segments; ii++)
            {
                glBegin(GL_LINES);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex2f(2 * x + dist_x1, (0.5) * y + dist_y1); ///output vertex
                glVertex2f(2 * x + dist_x1, (0.5) * y + dist_y1-1); ///output vertex
                ///ring ta -1 kore upore arekta dilo jate kore thick hoi
                /// rotation matrix
                t = x;
                x = c * x - s * y;
                y = s * t + c * y;
            }
            glEnd();


            /// The Pole

            glBegin(GL_LINES);
            glColor3f(0.560784f, 0.737255f, 0.560784f);
            glVertex2f(190.0, 185.0);
            glVertex2f(190.0, 150.0);
            glEnd();
            glBegin(GL_LINES);
            glColor3f(0.560784f, 0.737255f, 0.560784f);
            glVertex2f(191.0, 186.0);
            glVertex2f(191.0, 151.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.560784f, 0.737255f, 0.560784f);
            glVertex2f(190.0, 165.0);
            glVertex2f(200.0, 150.0);
            glEnd();
            glBegin(GL_LINES);
            glColor3f(0.560784f, 0.737255f, 0.560784f);
            glVertex2f(191.0, 165.0);
            glVertex2f(201.0, 150.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.560784f, 0.737255f, 0.560784f);
            glVertex2f(200.0, 165.0);
            glVertex2f(200.0, 45.0);
            glEnd();
            glBegin(GL_LINES);
            glColor3f(0.560784f, 0.737255f, 0.560784f);
            glVertex2f(201.0, 166.0);
            glVertex2f(201.0, 46.0);
            glEnd();

            /*-------The Player-------*/

            if (level == 2)
            {
                X_level = -30;

                /// Player's Face

                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                glBegin(GL_POLYGON);
                glColor3f( 0.0f,  0.0f, 0.0f);
                dist_x1 = 60.0, dist_y1 = 92.5, r1 = 10, num_segments=1000;
                for (int ii = 0; ii < num_segments; ii++)
                {
                    float alpha = 2.0f * 3.1415926f * float(ii) / float(num_segments); ///get the current angle
                    float x = r1 * cosf(alpha); ///calculate the x component
                    float y = r1 * sinf(alpha); ///calculate the y component
                    glVertex2f(x + dist_x1, y + dist_y1);
                }
                glEnd();

                /// Player's Face Boundary
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                glBegin(GL_POLYGON);
                glColor3f( 0.96f,  0.80f, 0.69f);
                dist_x1 = 60.0, dist_y1 = 92.5, r1 = 10, num_segments=1000;
                for (int ii = 0; ii < num_segments; ii++)
                {
                    float alpha = 2.0f * 3.1415926f * float(ii) / float(num_segments); ///get the current angle
                    float x = (r1-0.5) * cosf(alpha); ///calculate the x component
                    float y = (r1-0.5) * sinf(alpha); ///calculate the y component
                    glVertex2f(x + dist_x1, y + dist_y1); ///output vertex
                }
                glEnd();

                /// Player's Hand

                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(80.0, 105.0);
                glVertex2f(60.0, 70.0);
                glEnd();

                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(81.0, 105.0);
                glVertex2f(61.0, 70.0);
                glEnd();

                /// Player's Body

                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(60.0, 82.5);
                glVertex2f(60.0, 57.5);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(61.0, 82.5);
                glVertex2f(61.0, 57.5);
                glEnd();

                /// Player's Legs

                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(60.0, 57.5);
                glVertex2f(71.0, 40.0);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(61.0, 57.5);
                glVertex2f(72.0, 40.0);
                glEnd();

                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(60.0, 57.5);
                glVertex2f(49.0, 40.5);
                glEnd();
                glBegin(GL_LINES);
                glColor3f( 0.96f,  0.80f, 0.69f);
                glVertex2f(61.0, 57.5);
                glVertex2f(50.0, 40.5);
                glEnd();
            }

            ///*---------The BasketBall-------*///

            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f,0.4f);
            for (int ii = 0; ii < num_segments; ii++)
            {
                float alpha = 2.0f * 3.1415926f * float(ii) / float(num_segments); ///get the current angle
                float x = r * cosf(alpha); ///calculate the x component
                float y = r * sinf(alpha); ///calculate the y component
                glVertex2f(x + 50 + dist_x - X_level, y + 200 + dist_y); ///output vertex
            }
            glEnd();

            ///*------Boundary of ball---*//

            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glBegin(GL_POLYGON);
            glColor3f(0.72f, 0.45f, 0.20f);
            for (int ii = 0; ii < num_segments; ii++)
            {
                float alpha = 2.0f * 3.1415926f * float(ii) / float(num_segments); ///get the current angle
                float x = (r-0.3) * cosf(alpha); ///calculate the x component
                float y = (r-0.3) * sinf(alpha); ///calculate the y component
                glVertex2f(x + 50 + dist_x - X_level, y + 200 + dist_y); ///output vertex
            }
            glEnd();

            ///*----Strips of ball----*///

            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f,0.0f);
            alpha = 2.0f * 3.1415926f * float(time) / float(num_segments); ///get the current angle
            x = r * cosf(alpha); ///calculate the x component
            y = r * sinf(alpha);  ///calculate the y component
            float x1 = r * cosf(180+alpha); ///calculate the x component
            float y1 = r * sinf(180+alpha);  ///calculate the y component
            float x2 = r * cosf(270+alpha); ///calculate the x component
            float y2 = r * sinf(270+alpha);  ///calculate the y component
            float x3 = r * cosf(90+alpha); ///calculate the x component
            float y3 = r * sinf(90+alpha);  ///calculate the y component
            glVertex2f(x + 50 + dist_x - X_level, y + 200 + dist_y);
            glVertex2f(x1 + 50 + dist_x- X_level, y1 + 200 + dist_y);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f,0.0f);
            glVertex2f(x2 + 50 + dist_x - X_level, y2 + 200 + dist_y);
            glVertex2f(x3 + 50 + dist_x - X_level, y3 + 200 + dist_y);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0.0f, 0.0f,0.0f);
            glVertex2f(x1 + 50 + dist_x - X_level, y1 + 200 + dist_y);
            glVertex2f(x3 + 50 + dist_x - X_level, y3 + 200 + dist_y);
            glEnd();

            ///*---------Defining Trajectory Of The Ball--------*///

            dist_x = time;
            if (angle == 90)
                dist_y = (dist_x / 0.0001) - ((9.81 * dist_x * dist_x) / (2 * 2800 * 0.0001 * 0.0001));
            else
                dist_y = dist_x * tan(theta) - ((9.81 * dist_x * dist_x) / (2 * velocity * velocity * cos(theta) * cos(theta)));
            dist_x = (0.5) * dist_x;
            dist_y = dist_y - 90;

            /// IF Ball hits the Rim and Falls on the ground #NO SCORE

            if (((dist_y < -35.5 && dist_y > -40.5 && dist_x < (110+X_level) && dist_x > (109+X_level)) || flag1 == 1) && flag != 1 && flag2 != 1 && flag3 != 1)
            {
                if (flag1 == 0)
                {
                    X_BallHitsRim = dist_x;
                    Y_BallHitsRim = dist_y;
                }
                flag1 = 1;
                dist_x = RelativeX_BallHitsRim;
                RelativeX_BallHitsRim++;
                dist_y = -((9.81 * dist_x * dist_x) / (2 * 2800));
                dist_x = X_BallHitsRim - (RelativeX_BallHitsRim * 0.5);
                dist_y = Y_BallHitsRim + dist_y;
                usleep(30);

                /// IF Ball hits Ground after it hits the pole
                if (dist_y < -151)
                {
                    break;
                }
            }

            /// IF Ball hits the ceiling #NO SCORE
            else if ((dist_y > -5 || flag == 1) && (flag2 != 1))
            {
                if (flag == 0)
                {
                    X_BallHitsCeiling = dist_x;
                    flag = 1;
                }
                dist_x = X_BallHitsCeiling;
                dist_y = Y_BallHitsCeiling--;
                usleep(100);
            }

            /// IF Ball goes into the Basket #SCORE
            else if ((dist_x > (110+X_level) && dist_x < (140+X_level) && dist_y < -35.5 && dist_y > -40.5 && flag2 != 1 && flag != 1 && flag1 != 1) || flag3 == 1)
            {
                if (flag3 == 0)
                {
                    X_BallInBasket = dist_x;
                    Y_BallInBasket = dist_y;
                    score++;
                }
                glColor3f(1.0f, 0.5f, 0.0f);
                output(30,120,"YO! THAT'S A BASKET MAN :) ");
                flag3 = 1;
                dist_x = X_BallInBasket;
                dist_y = Y_BallInBasket--;
                usleep(100);  //thread ke eto miliseconds er jonne pause kore dei
            }
            //  else
            //    usleep(100);

            /// IF Ball hits the Ground
            if (dist_y < -151 && flag2 != 1)
                break;


            /// IF Ball hits The Pole #NO SCORE
            if (dist_x > (145 + X_level) || flag2 == 1)
            {
                if (flag2 == 0)
                {
                    X_BallHitsPole = dist_x;
                    Y_BallHitsPole = dist_y;
                }
                flag2 = 1;
                dist_x = RelativeX_BallHitsPole;
                RelativeX_BallHitsPole++;
                dist_y = -((9.81 * dist_x * dist_x) / (2 * velocity * velocity));
                dist_x = X_BallHitsPole - (RelativeX_BallHitsPole * 0.5);
                dist_y = Y_BallHitsPole + dist_y;

                ///IF Ball hits Ground after it hits the pole
                if (dist_y < -151)  //y er -151 holo amar ground
                    break;
            }

            glEnd();
            glFlush();
        }

        if (attempts != 0)
        {
            cout << "\nAttempt: " << attempts << "\n";
            cout << "Angle: ";
            cin >> angle;
            cout << "Velocity: ";
            cin >> velocity;
        }
        attempts--;
    }
    cout << "                            ------------------\n";
    cout << "                                KHELA SHESH\n";
    cout << "                            ------------------\n";
}
int main(int argc, char * argv[])
{
    angle = 0;
    velocity = 0;
    cout << "                      -------------------------------\n";
    cout << "                              BASKETBALL GAME\n";
    cout << "                      -------------------------------\n\n";

    cout<<"Enter Number of Attempts you want to try!: ";
    cin>>attempts;
    while(attempts>15)
    {
        cout<<"Not more than 15 times!!\n\n\nTry again\n\n";
        cin>>attempts;
    }
//    cout<<
//    string x;
//    cin>>x;
//

    cout<<"\nInput the Angle & Velocity You Wish to SHOOT the basketball\n\nN.B: Angle Should Range From 0 - 89 & Velocity in range 10-100\n\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(700, 0);
    glutCreateWindow("THE BASKETBALL GAME");
    init2D(0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
