#ifndef defination_H
#define defination_H

typedef enum{
	INITIAL,
	LED1_OFF,
	LED2_OFF,
	LED3_OFF,
	LED4_OFF,
	LED1_ON,
	LED2_ON,
	LED3_ON,
	LED4_ON,
	Final
}State;

typedef struct{
	State state;
}TaskBlock;

#define yield(x) 				(x)->state = __LINE__; break; case __LINE__ : ;
#define startTask(x) 			switch( (x)->state) { case 0: ;
#define initTaskBlock(x)		(x)->state = 0;
#define endTask(x) 				} ;

#define ONE_HUNDRED_MILI_SEC 			100
#define TWO_HUNDRED_MILI_SEC		 	200
#define TWO_HUNDRED_FOURTY_MILI_SEC 	240
#define ONE_HUNDRED_TWENTY_MILI_SEC 	120
#define FIVE_HUNDRED_MILI_SEC 			500
#define ONE_SEC 						1000
#define THREE_SEC 						3000

#endif // defination_H
