#include "ShippingStatus.h"


ShippingStatus::ShippingStatus() {
	status_ = "";
	location_ = "";
	time_ = 0;
	prev_ = nullptr;
	next_ = nullptr;
}

ShippingStatus::~ShippingStatus()
{

}

ShippingStatus::ShippingStatus(const string& status, const string& location, const time_t& timeUpdated, ShippingStatus* prev, ShippingStatus* next) {
	status_ = status;
	location_ = location;
	time_ = timeUpdated;
	prev_ = prev;
	next_ = next;
}

string ShippingStatus::m_getStatus() {
	return status_;
}

string ShippingStatus::m_getLocation() {
	return location_;
}


time_t ShippingStatus::m_getTime() {
	return time_;
}

ShippingStatus* ShippingStatus::m_getPrev() {
	return prev_;
}

ShippingStatus* ShippingStatus::m_getNext() {
	return next_;
}

int ShippingStatus::m_setStatus(const string& status) {
	status_ = status;
	return 1;
}
int ShippingStatus::m_setLocation(const string& location) {
	location_ = location;
	return 1;
}
int ShippingStatus::m_setTime(const time_t& timeUpdated) {
	time_ = timeUpdated;
	return 1;
}
int ShippingStatus::m_setPrev(ShippingStatus* prev) {
	prev_ = prev;
	return 1;
}
int ShippingStatus::m_setNext(ShippingStatus* next) {
	next_ = next;
	return 1;
}