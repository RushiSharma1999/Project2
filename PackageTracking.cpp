#include "PackageTracking.h"

PackageTracking::PackageTracking(const string& strnum) {
	intnumUpdate_ = 0;                            // initially empty
	header_ = new ShippingStatus;              // create sentinels
	trailer_ = new ShippingStatus;
	header_->m_setNext(trailer_);             // have them point to each other
	trailer_->m_setPrev(header_);
	current_ = header_; //set iterator
	strnum_ = strnum;

}
PackageTracking::~PackageTracking() {
	if (!m_isEmpty()) m_clear();     // remove all but sentinels
	delete header_;                            // remove the sentinels
	delete trailer_;

}
// add a new update before trailer end
int PackageTracking::m_addUpdate(const string& status_, const string& location_, const time_t& timeUpdated) {
	ShippingStatus* ptr_newupdate = new ShippingStatus(status_, location_, timeUpdated, nullptr, nullptr);
	if (!ptr_newupdate) return -1;
	ptr_newupdate->m_setNext(trailer_);
	ShippingStatus* ptr_pretrailer = trailer_->m_getPrev();
	ptr_newupdate->m_setPrev(ptr_pretrailer);
	ptr_pretrailer->m_setNext(ptr_newupdate);
	trailer_->m_setPrev(ptr_newupdate);
	intnumUpdate_++;
	current_ = ptr_newupdate;// move cur pointer

	return 1;
}
/*
int m_addUpdate(const ShippingStatus& newupdate)// add a new update before trailer end
{
return 1;
}
*/

int PackageTracking::m_removeUpdate()// remove the update before trailer end
{
	ShippingStatus* ptr_pretrailer = trailer_->m_getPrev();
	if ((ptr_pretrailer == header_) || !ptr_pretrailer)
		return -1;
	ShippingStatus* ptr_prepretrailer = ptr_pretrailer->m_getPrev();
	if (!ptr_prepretrailer) return -1;
	ptr_prepretrailer->m_setNext(trailer_);
	trailer_->m_setPrev(ptr_prepretrailer);
	intnumUpdate_--;
	delete ptr_pretrailer;

	return 1;
}

int PackageTracking::m_moveBackward()//move iterator one step towards header
{
	ShippingStatus* ptr_curpre = current_->m_getPrev();
	if (ptr_curpre == header_)
		return -1;
	current_ = ptr_curpre;
	return 1;
}

int PackageTracking::m_moveForward()//move iterator one step towards trailer
{
	ShippingStatus* ptr_curnext = current_->m_getNext();
	if (ptr_curnext == trailer_)
		return -1;
	current_ = ptr_curnext;
	return 1;
}

string PackageTracking::m_getLocation()//return the location_ of the current update
{
	if (!current_) return "N/A";
	return current_->m_getLocation();
}

time_t PackageTracking::m_getTime()//return the time_ of the current update
{
	if (!current_) return 0;
	time_t tmp_tt = current_->m_getTime();
	return tmp_tt;
}

string PackageTracking::m_getStatus()//return the status_ of the current update
{
	if (!current_) return "N/A";
	return current_->m_getStatus();
}

int PackageTracking::m_getNumofUpdate() const // get the total numbers of shipping status_ updates
{
	return intnumUpdate_;
}

int PackageTracking::m_printPreviousUpdates() //print all previous updates in the shipping chain when the package was shipped
{

	if (m_isEmpty() || (current_->m_getPrev() == header_))
	{
		cout << "no previous updates" << endl;
		return -1;
	}
	ShippingStatus* ptr_cur = current_;
	while (current_->m_getPrev() != header_)
	{
		m_moveBackward();
		cout << m_getTime() << ": " << m_getStatus() << ": " << m_getLocation() << endl;

	}
	current_ = ptr_cur;// reset current_
	return 1;
}
int PackageTracking::m_printFollowingUpdates()//print all following updates including the current update you are viewing.
{

	cout << m_getTime() << ": " << m_getStatus() << ": " << m_getLocation() << endl;
	if (m_isEmpty() || (current_->m_getNext() == trailer_))
	{
		cout << "no following updates" << endl;
		return -1;
	}
	ShippingStatus* ptr_cur = current_;
	while (current_->m_getNext() != trailer_)
	{
		m_moveForward();
		cout << m_getTime() << ": " << m_getStatus() << ": " << m_getLocation() << endl;
	}
	current_ = ptr_cur;// reset current_
	return 1;
}

int PackageTracking::m_printFullTracking()//print all the updates in the tracking chain.
{
	cout << "Tracking number: " << m_getTrackingnumber() << endl;
	if (m_isEmpty()) {
		cout << "no updates" << endl;
		return -1;
	}
	ShippingStatus* ptr_cur = current_;
	while (current_ != header_->m_getNext())// move current_ to the first element
		m_moveBackward();

	while (current_ != trailer_->m_getPrev())//iterate and print
	{
		cout << m_getTime() << ": " << m_getStatus() << ": " << m_getLocation() << endl;
		m_moveForward();
	}
	if (current_ == trailer_->m_getPrev())//the only data element or the last element
		cout << m_getTime() << ": " << m_getStatus() << ": " << m_getLocation() << endl;

	current_ = ptr_cur;
	return 1;
}

bool PackageTracking::m_isEmpty() const//check empty
{
	if (header_->m_getNext() == trailer_)
		return true;
	return false;
}

void PackageTracking::m_clear()//remove all but sentinels
{
	while (!m_isEmpty())
		m_removeUpdate();
}

string PackageTracking::m_getTrackingnumber() {
	return strnum_;
}

int PackageTracking::m_viewUpdate(const time_t& timeUpdated)//view an update.
{
	if (m_isEmpty()) return -1;
	current_ = header_->m_getNext();
	while ((current_->m_getTime() != timeUpdated) && (current_->m_getNext() != trailer_))
		m_moveForward();
	return 1;
}
//read the full tracking chain from a file and follow the commands as specified in the file
int PackageTracking::readTrackingFile(string fileName) {

	ifstream infile;
	infile.open(fileName);

	while (infile)
	{
		string tmp_strline;
		if (!getline(infile, tmp_strline)) break;

		//cout<<tmp_strline<<endl;
		if (tmp_strline == "new") {
			if (!getline(infile, tmp_strline)) break;//get next line
			istringstream tmp_str(tmp_strline);
			string tmp_loc, tmp_sta, tmp_strtime;
			time_t tmp_tt;
			if (!getline(tmp_str, tmp_sta, ';')) break;
			if (!getline(tmp_str, tmp_loc, ';')) break;
			if (!getline(tmp_str, tmp_strtime, ';')) break;
			stringstream geek(tmp_strtime);
			int i_time = 0;
			geek >> i_time;
			tmp_tt = (time_t)i_time;
			//cout<<tmp_loc<<";"<<tmp_sta<<";"<<tmp_strtime<<endl;
			m_addUpdate(tmp_sta, tmp_loc, tmp_tt);

		}
		else if (tmp_strline == "back") {
			m_moveBackward();
		}
		else if (tmp_strline == "forward") {
			m_moveForward();
		}
		else {
			return -2;
		}
	}
	if (!infile.eof())
	{
		return -1;
	}
	return 1;
}