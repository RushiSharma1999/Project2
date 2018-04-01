#ifndef PACKAGETRACKING_H
#define PACKAGETRACKING_H

#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include "ShippingStatus.h"
using namespace std;

class PackageTracking {
public:
	PackageTracking(const string& strnum);
	~PackageTracking();

	int m_addUpdate(const string& status_, const string& location_, const time_t& timeUpdated);// add a new update before trailer end
																							 //int m_addUpdate(const ShippingStatus& newupdate);// add a new update before trailer end
	int m_removeUpdate();// remove the update before trailer end

	int m_moveBackward();//move iterator one step towards header
	int m_moveForward();//move iterator one step towards trailer

	string m_getLocation();//return the location_ of the current update
	time_t m_getTime();//return the time_ of the current update
	string m_getStatus();//return the status_ of the current update
	int m_getNumofUpdate() const; // get the total numbers of shipping status_ updates

	int m_viewUpdate(const time_t& timeUpdated);//view an update.

	int m_printPreviousUpdates(); //print all previous updates in the shipping chain when the package was shipped,
	int m_printFollowingUpdates();//print all following updates including the current update you are viewing.

	int m_printFullTracking();//print all the status_ updates in the tracking chain.
	bool m_isEmpty() const;//check empty
	void m_clear();//remove all but sentinels

	string m_getTrackingnumber();
	//read the full tracking chain from a file and follow the commands as specified in the file
	int readTrackingFile(string fileName);


private:
	ShippingStatus *header_, *trailer_, *current_;//header, trailer, iterator
	int intnumUpdate_;//number of updates
	string strnum_;//package tracking number
};

#endif /* PACKAGETRACKING_H */