#ifndef SHIPPINGSTATUS_H
#define SHIPPINGSTATUS_H

#pragma once

#include <stdio.h>
#include <string>
using namespace std;

class ShippingStatus {
public:
	ShippingStatus();
	ShippingStatus(const string& status_, const string& location_, const time_t& timeUpdated, ShippingStatus* prev, ShippingStatus* next);
	~ShippingStatus();
	string m_getStatus();
	string m_getLocation();
	time_t m_getTime();
	ShippingStatus* m_getPrev();
	ShippingStatus* m_getNext();

	int m_setStatus(const string& status_);
	int m_setLocation(const string& location_);
	int m_setTime(const time_t& timeUpdated);
	int m_setPrev(ShippingStatus* prev);
	int m_setNext(ShippingStatus* next);

private:
	string status_;
	string location_;
	time_t time_;
	ShippingStatus *prev_, *next_;
	
};


#endif /* SHIPPINGSTATUS_H */