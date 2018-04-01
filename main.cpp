//#include <iostream>
//
//#include <fstream>
//
//#include <list>
//
//#include <string>
//
//#include <stdexcept>
//
//#include "PackageTracking.h"
//
//#include "ShippingStatus.h"
//
//using namespace std;
//
//template <typename T>
//
//bool testAnswer(const string &nameOfTest, const T& received, const T& expected);
//
//template <typename T>
//
//bool testArrays(const string& nameOfTest, const T& received, const T& expected, const int& size);
//
//int main() {
//
//	// Test only ShippingStatus class
//
//	ShippingStatus testStatus01("Package has left seller facility and is in transit to carrier", "N/A", 1515978000);
//
//	testAnswer("testStatus01.m_getLocation() test", testStatus01.m_getLocation(), string("N/A"));
//
//	testAnswer("testStatus01.m_getStatus() test", testStatus01.m_getStatus(), string("Package has left seller facility and is in transit to carrier"));
//
//	testAnswer("testStatus01.m_getTime() test", testStatus01.m_getTime(), time_t(1515978000));
//
//
//
//	ShippingStatus testStatus02("Shipment arrived at Amazon facility", "Hebron, KENTUCKY US", 1516111440);
//
//	testAnswer("testStatus02.m_getLocation() test", testStatus02.m_getLocation(), string("Hebron, KENTUCKY US"));
//
//	testAnswer("testStatus02.m_getStatus() test", testStatus02.m_getStatus(), string("Shipment arrived at Amazon facility"));
//
//	testAnswer("testStatus02.m_getTime() test", testStatus02.m_getTime(), time_t(1516111440));
//
//
//
//	ShippingStatus testStatus03("Shipment arrived at Amazon facility", "San Bernardino, CALIFORNIA US", 1516366740);
//
//	testAnswer("testStatus03.m_getLocation() test", testStatus03.m_getLocation(), string("San Bernardino, CALIFORNIA US"));
//
//	testAnswer("testStatus03.m_getStatus() test", testStatus03.m_getStatus(), string("Shipment arrived at Amazon facility"));
//
//	testAnswer("testStatus03.m_getTime() test", testStatus03.m_getTime(), time_t(1516366740));
//
//
//
//	// Test PackageTracking class
//
//	string tmp_strtrackingnumber;//
//
//	tmp_strtrackingnumber = "TBA688567081000";
//
//	PackageTracking testPackageTracking(tmp_strtrackingnumber);
//
//	testPackageTracking.m_addUpdate(testStatus01.m_getStatus(), testStatus01.m_getLocation(), testStatus01.m_getTime());
//
//	testPackageTracking.m_addUpdate(testStatus02.m_getStatus(), testStatus02.m_getLocation(), testStatus02.m_getTime());
//
//	testPackageTracking.m_addUpdate(testStatus03.m_getStatus(), testStatus03.m_getLocation(), testStatus03.m_getTime());
//
//
//
//	testPackageTracking.m_setCurrent(testStatus01.m_getTime());
//
//	testAnswer("testPackageTracking.m_getLocation()", testPackageTracking.m_getLocation(), string("N/A"));
//
//	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Package has left seller facility and is in transit to carrier"));
//
//
//
//	testPackageTracking.m_setCurrent(testStatus02.m_getTime());
//
//	testAnswer("testPackageTracking.m_getLocation()", testPackageTracking.m_getLocation(), string("Hebron, KENTUCKY US"));
//
//	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Shipment arrived at Amazon facility"));
//
//
//
//	// Test back and forward
//
//	testPackageTracking.m_moveForward();
//
//	testAnswer("testPackageTracking.m_moveForward()", testPackageTracking.m_getLocation(), string("San Bernardino, CALIFORNIA US"));
//
//	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Shipment arrived at Amazon facility"));
//
//	testAnswer("testPackageTracking.m_getTime( )", testPackageTracking.m_getTime(), time_t(1516366740));
//
//	testPackageTracking.m_moveBackward();
//
//	testAnswer("testPackageTracking.m_moveBackward()", testPackageTracking.m_getLocation(), string("Hebron, KENTUCKY US"));
//
//	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Shipment arrived at Amazon facility"));
//
//	testAnswer("testPackageTracking.m_getTime( )", testPackageTracking.m_getTime(), time_t(1516111440));
//
//
//
//	// Test PackageTracking reading from a file
//
//	PackageTracking testPackageTracking01(tmp_strtrackingnumber);
//
//	string tmp_filename = tmp_strtrackingnumber + ".txt";
//
//	if (!testPackageTracking01.m_readTrackingFile(tmp_filename)) {
//
//		cout << "Failed to read tracking file" << endl;
//
//		return (-1);
//
//	}
//
//	testAnswer("testPackageTracking01.m_getLocation()", testPackageTracking01.m_getLocation(), string("Chino, US"));
//
//	testAnswer("testPackageTracking01.m_getStatus( )", testPackageTracking01.m_getStatus(), string("Package arrived at a carrier facility"));
//
//	testAnswer("testPackageTracking01.m_getTime( )", testPackageTracking01.m_getTime(), time_t(1516410060));
//
//
//
//	// Test history printing
//
//	cout << "\nPrinting all previous updates:\n";
//
//	testPackageTracking01.m_printPreviousUpdates();
//
//	cout << "\nPrinting all following updates:\n";
//
//	testPackageTracking01.m_printFollowingUpdates();
//
//	cout << "\nPrinting Full History:\n";
//
//	testPackageTracking01.m_printFullTracking();
//
//
//
//	//system("pause");
//
//	return 1;
//
//}
//
//template <typename T>
//
//bool testAnswer(const string &nameOfTest, const T& received, const T& expected) {
//
//	if (received == expected) {
//
//		cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
//
//		return true;
//
//	}
//
//	cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
//
//	return false;
//
//}
//
//template <typename T>
//
//bool testArrays(const string& nameOfTest, const T& received, const T& expected, const int& size) {
//
//	for (int i = 0; i < size; i++) {
//
//		if (received[i] != expected[i]) {
//
//			cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
//
//			return false;
//
//		}
//
//	}
//
//
//
//	cout << "PASSED " << nameOfTest << ": expected and received matching arrays" << endl;
//
//	return true;
//
//}





//
//allowed to use or refer to these examples
//
//https://github.com/apanangadan/CSUF-CPSC_131/blob/master/DLinkedList.h
//
//https://github.com/kevinwortman/thedatastructures/blob/master/doubly_linked_list.hh
//
//https://github.com/kevinwortman/thedatastructures/blob/master/doubly_linked_list_example.cc



#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>

#include "PackageTracking.h"
#include "ShippingStatus.h"

using namespace std;

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected) {
	if (received == expected) {
		cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
		return true;
	}
	cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
	return false;
}

template <typename T>
bool testArrays(const string& nameOfTest, const T& received, const T& expected, const int& size) {
	for (int i = 0; i < size; i++) {
		if (received[i] != expected[i]) {
			cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
			return false;
		}
	}

	cout << "PASSED " << nameOfTest << ": expected and received matching arrays" << endl;
	return true;
}


int main(int argc, char *argv[]) {
	// Test only ShippingStatus class
	ShippingStatus testStatus01("Package has left seller facility and is in transit to carrier", "N/A", 1515978000, nullptr, nullptr);
	testAnswer("testStatus01.m_getLocation() test", testStatus01.m_getLocation(), string("N/A"));
	testAnswer("testStatus01.m_getStatus() test", testStatus01.m_getStatus(), string("Package has left seller facility and is in transit to carrier"));
	testAnswer("testStatus01.m_getTime() test", testStatus01.m_getTime(), time_t(1515978000));

	ShippingStatus testStatus02("Shipment arrived at Amazon facility", "Hebron, KENTUCKY US", 1516111440, nullptr, nullptr);
	testAnswer("testStatus02.m_getLocation() test", testStatus02.m_getLocation(), string("Hebron, KENTUCKY US"));
	testAnswer("testStatus02.m_getStatus() test", testStatus02.m_getStatus(), string("Shipment arrived at Amazon facility"));
	testAnswer("testStatus02.m_getTime() test", testStatus02.m_getTime(), time_t(1516111440));

	ShippingStatus testStatus03("Shipment arrived at Amazon facility", "San Bernardino, CALIFORNIA US", 1516366740, nullptr, nullptr);
	testAnswer("testStatus03.m_getLocation() test", testStatus03.m_getLocation(), string("San Bernardino, CALIFORNIA US"));
	testAnswer("testStatus03.m_getStatus() test", testStatus03.m_getStatus(), string("Shipment arrived at Amazon facility"));
	testAnswer("testStatus03.m_getTime() test", testStatus03.m_getTime(), time_t(1516366740));


	// Test PackageTracking class
	string tmp_strtrackingnumber;//
	tmp_strtrackingnumber = "TBA688567081000";//hard-coded testing, could change to use argv for testing
	PackageTracking testPackageTracking(tmp_strtrackingnumber);
	testPackageTracking.m_addUpdate(testStatus01.m_getStatus(), testStatus01.m_getLocation(), testStatus01.m_getTime());
	testPackageTracking.m_addUpdate(testStatus02.m_getStatus(), testStatus02.m_getLocation(), testStatus02.m_getTime());
	testPackageTracking.m_addUpdate(testStatus03.m_getStatus(), testStatus03.m_getLocation(), testStatus03.m_getTime());

	testPackageTracking.m_viewUpdate(testStatus01.m_getTime());
	testAnswer("testPackageTracking.m_getLocation()", testPackageTracking.m_getLocation(), string("N/A"));
	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Package has left seller facility and is in transit to carrier"));

	testPackageTracking.m_viewUpdate(testStatus02.m_getTime());
	testAnswer("testPackageTracking.m_getLocation()", testPackageTracking.m_getLocation(), string("Hebron, KENTUCKY US"));
	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Shipment arrived at Amazon facility"));

	// Test back and forward
	testPackageTracking.m_moveForward();
	testAnswer("testPackageTracking.m_moveForward()", testPackageTracking.m_getLocation(), string("San Bernardino, CALIFORNIA US"));
	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Shipment arrived at Amazon facility"));
	testAnswer("testPackageTracking.m_getTime( )", testPackageTracking.m_getTime(), time_t(1516366740));
	testPackageTracking.m_moveBackward();
	testAnswer("testPackageTracking.m_moveBackward()", testPackageTracking.m_getLocation(), string("Hebron, KENTUCKY US"));
	testAnswer("testPackageTracking.m_getStatus( )", testPackageTracking.m_getStatus(), string("Shipment arrived at Amazon facility"));
	testAnswer("testPackageTracking.m_getTime( )", testPackageTracking.m_getTime(), time_t(1516111440));


	// Test PackageTracking reading from a file
	PackageTracking testPackageTracking01(tmp_strtrackingnumber);
	string tmp_filename = tmp_strtrackingnumber + ".txt";
	testPackageTracking01.readTrackingFile(tmp_filename);
	testAnswer("testPackageTracking01.m_getLocation()", testPackageTracking01.m_getLocation(), string("Chino, US"));
	testAnswer("testPackageTracking01.m_getStatus( )", testPackageTracking01.m_getStatus(), string("Package arrived at a carrier facility"));
	testAnswer("testPackageTracking01.m_getTime( )", testPackageTracking01.m_getTime(), time_t(1516410060));


	// Test history printing
	cout << "\nPrinting all previous updates:\n";
	testPackageTracking01.m_printPreviousUpdates();
	cout << "\nPrinting all following updates:\n";
	testPackageTracking01.m_printFollowingUpdates();
	cout << "\nPrinting Full History:\n";
	testPackageTracking01.m_printFullTracking();

	return 1;

	system("pause");
}