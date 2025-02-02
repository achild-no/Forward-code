#include  "Robot.h"
#include "main.h"

using namespace std;
using namespace pros;


// commit practice (LW)
Controller Robot::Controller1(E_CONTROLLER_MASTER);

//  back wheels
Motor Robot::LeftBackWheel(16);
Motor Robot::RightBackWheel(15);
// front wheels
Motor Robot::LeftFrontWheel(20);
Motor Robot::RightFrontWheel(11);

//others
Motor Robot::Intake(2);
Motor Robot::Spinner1(1);
Motor Robot::Spinner2(3, true);
Motor Robot::Roller(10);
ADIDigitalOut Robot::pneumatics('A');


std::map<std::string, std::unique_ptr<pros::Task>> Robot::tasks;
std::atomic<double> Robot::x = 0;

bool Robot::task_exists(string s) {
  return tasks.find(s) != tasks.end();
}


void Robot::start_task(std::string name, void (*func)(void *)) {
  if (!task_exists(name)) {
    tasks.insert(std::pair<std::string, std::unique_ptr<pros::Task>>(name, std::move(std::make_unique<pros::Task>(func, &x, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, ""))));
  }
}

void Robot::end_task(string s) {
  if(task_exists(s)) {
    tasks.erase(s);
  }
}

void Robot::drive(int power, int turn) {
  Robot::LeftBackWheel = power + turn;
  Robot::LeftFrontWheel = power + turn;
  Robot::RightBackWheel = -power + turn;
  Robot::RightFrontWheel = -power + turn;

}
int booper;


  void Robot::driveControl(void *ptr) {
  while(true)
  {
    if(Controller1.get_digital(DIGITAL_R1)) {
      Robot::Intake = 127;
    }
    else if(Controller1.get_digital(DIGITAL_R2)) {
      Robot::Intake = -127;
    }
    else {
      Robot::Intake = 0;
    }
    int booper;

    (Robot::Controller1.get_digital(DIGITAL_A) && booper == 1.0); {
    }

      // 4-loop one button function
      // extending
      Robot::pneumatics.set_value(0);
      booper = 2;
      }
       booper = 3;
       if (!Robot::Controller1.get_digital(DIGITAL_LEFT) && booper == 2.0) {
     }
     if (Robot::Controller1.get_digital(DIGITAL_LEFT) && booper == 3.0) {
      // retracting
      Robot::pneumatics.set_value(1);
      booper = 4;
     }
     if (!Robot::Controller1.get_digital(DIGITAL_LEFT) && booper == 4.0) {
     booper = 1;
     }
/*    if(Robot::Controller1.get_digital(DIGITAL_A)) {

      Robot::pneumatics.set_value(1);
    }
    else {
      Robot::pneumatics.set_value(0);
    }
*/
    if(Robot::Controller1.get_digital(DIGITAL_B)) {

      ;
    }

/*
    if(Robot::Controller1.get_digital(DIGITAL_X)) {
      Robot::Spinner1 = -100;
      Robot::Spinner2 = -100;
      delay(100); // need to test this number
      Robot::pneumatics.set_value(1);
      delay(100);
      Robot::pneumatics.set_value(0);
      Robot::Spinner1 = 0;
      Robot::Spinner2 = 0;
    }
*/
    if(Controller1.get_digital(DIGITAL_R1)) {
      Robot::Intake = 127;
      Robot::Roller = 100;
    }


     else if(Controller1.get_digital(DIGITAL_R2)) {
      Robot::Intake = -127;
      Robot::Roller = 100;
    }

    else {
      Robot::Intake = 0;
      Robot::Roller = 0;
    }

    if(Controller1.get_digital(DIGITAL_L2)) {
       Robot::Spinner1 = -100;
       Robot::Spinner2 = -100;
     }
     else {
       Robot::Spinner1 = 0;
       Robot::Spinner2 = 0;
     }
     if(Robot::Controller1.get_digital(DIGITAL_X)) {
         int power = Robot::Controller1.get_analog(ANALOG_LEFT_Y);
         int turn = Robot::Controller1.get_analog(ANALOG_RIGHT_X);
         drive(power, turn);
      }
    }
}
