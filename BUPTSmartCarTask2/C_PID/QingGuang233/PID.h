#ifndef __PID_H
#define __PID_H

typedef struct {
	float kp;
	float ki;
	float kd;
    float kf; //ǰ������
	float target;
    float last_target;
	float pos;
	float last_err;
    float integral;
}PID;

int PID_Init(PID *pid);            //��ʼ��PID�ṹ��
int PID_SetParameter(float kp, float ki, float kd,float kf, PID* pid);     //����PID����
int PID_SetTarget(float target,PID* pid);    //������һ��Ŀ��λ��
float PID_PostionalPID(PID* pid);    //λ��ʽPIDʵ��
float PID_IncrementalPID(PID* pid);    //����ʽPIDʵ��
float PID_FeedforwardIncrementalPID(PID* pid);  //ǰ��ʽ����PIDʵ��

#endif