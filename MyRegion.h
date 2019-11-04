#pragma once

#include "..\Defs.h"
//#include "..\Generic_DS\Queue.h"
//#include "Order.h"
//#include "Motorcycle.h"
#include "..\Generic_DS\List.h"
#include "..\Generic_DS\PriorityQueue.h"
//#include "Restaurant.h"

//class Queue;
class Resturant;
class Order;
class Motorcycle;
class GUI;

class MyRegion
{
	REGION regionType;

	//PriorityQueue<Order*> frozen_VIP;
	PriorityQueue<Order*> VIP; 	//Waiting
	Queue<Order *> frozen;		//Waiting
	List<Order*> normal;		//Waiting
	PriorityQueue<Order*> deliveredOrders;

	PriorityQueue<Motorcycle*> InServiceMotorcycles;

	Queue<Motorcycle*> fastMotorcycles;    //Available Motorcycles 
	Queue<Motorcycle*> frozenMotorcycles;  //Available Motorcycles
	Queue<Motorcycle*> normalMotorcycles;  //Available Motorcycles

	bool rushHour;

	int getNormalOrderIndexFromID(int ID);

	int inServiceVipCounter;
	int inServiceFrozenCounter;
	int inServiceNormalCounter;
	int ServedVipCounter;
	int ServedFrozenCounter;
	int ServedNormalCounter;
public:
	Queue<Motorcycle*> lastStepMotorCycle;
	MyRegion(REGION regionType);

	// functions to add to each queue 
	void AddToNormal(Order* order);
	//void enqueueToFrozen_VIP(Order* order, double weight = 0);
	void enqueueToVIP(Order* order, double weight);
	void enqueueTofrozen(Order* order);

	void enqueueToFastMotorcycles(Motorcycle* order);
	void enqueueToFrozenMotorcycles(Motorcycle* order);
	void enqueueToNormalMotorcycles(Motorcycle* order);

	REGION GetRegionType() const;
	bool isRushHour();

	//bool dequeueFrozen_VIP_PHASE_1_ONLY(Order *& o);
	bool NormalOrdersRemoveLast(Order *& o);
	bool ExcludeNormalOrderFromNormalListByID(int ID, Order *& o);

	bool isThereAnyWaitingOrder();
	bool isThereAnyInServiceMotorcycles();

	void addMyOrdersToDrawOrdersArr(GUI * pGUI);

	int getNormalOrdersCount();
	int getFrozenOrdersCount();
	int getVipOrdersCount();
	int getNormalMotorcyclesCount();
	int getFrozenMotorcyclesCount();
	int getFastMotorcyclesCount();

	int GetDeliveredOrdersCount();
	Order ** GetDeliverdOrdersItemArray();
	double * GetDeliverdOrdersWeightArray();

	int getServedVIPCount();
	int getServedNormalCount();
	int getServedFrozenCount();

	int getInServiceVIPCount();
	int getInServiceNormalCount();
	int getInServiceFrozenCount();
	bool GetNormalByID(int ID, Order *& o);

	void printContents();

	void assignOrdersToMotorcycles(int currentTime);
	void handleReturnedMotorcycles(int currentTime/*, Restaurant * R_ptr*/);
	void handleAutoPromotion(int currentTime);
	//void doAssigningStuff(int currentTime);	

	double MyRegion::getAvgWait();
	double MyRegion::getAvgService();

};