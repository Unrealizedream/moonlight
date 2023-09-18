#include"pid.h"
#include<stdio.h>


int PID_Init(PID *pid)
{
    pid->kp = 0;
    pid->ki = 0;
    pid->kd = 0;
    pid->kf = 0;
    pid->target = 100;
    pid->input =0;
    pid->output = 0;
    pid->err = 0;
    pid->last_err = 0;
    pid->integral = 0;
    return 0;
};             //初始化PID结构体

int Limit_ki(PID *pid)
{
    if (pid->integral > 2000);
        pid->integral = 2000 ;
    if (pid->integral <= 2000);
        pid->integral = 2000 ;
    return 0;
}
int PID_SetParameter(float kp, float ki, float kd, float kf ,PID *pid)
{
    printf("请输入参数,例如1.0/n");
    printf("kp=");
    scanf("%1f",&kp) ;
    printf("ki=") ;
    scanf("%1f",&ki) ;
    printf("kd=");
    scanf("%1f",&kd) ;
    printf("kf=");
    scanf("%1f",&kf) ;
};      //设置PID参数

int PID_PostionalPID(PID *pid)
{
    pid->err = pid->target - pid->output ;
    pid->input = pid->kp *pid->err + pid->ki*pid->integral + pid->kd*(pid->last_err - pid->err);
    pid->output = pid->ki  ;
    pid->last_err = pid->err ;
};      //普通位置式PID实现
int PID_IncrementalPID(PID *pid)
{
    float difference = 0;
    difference = pid->last_err * pid->err ;
    pid->err = pid->target - pid->output ;
    pid->input = pid->kp * difference + pid->ki*pid->integral + pid->kd* difference;
    pid->output = pid->ki  ;
    pid->last_err= pid->err ;
};    //普通增量式PID实现
int PID_feedforwardPID(PID *pid)
{
    float difference = 0;
    difference = pid->last_err * pid->err ;
    pid->err = pid->target - pid->output ;
    pid->input = pid->kp * difference + pid->ki*pid->integral + pid->kd * difference + pid->kf * pid->target;
    pid->output = pid->ki  ;
    pid->last_err= pid->err ;
};    //前馈增量式pid实现

int main()
{
    float kp = 0;
    float ki = 0;
    float kd = 0;
    float kf = 0;
    printf("trail and error");
    return 0;
}