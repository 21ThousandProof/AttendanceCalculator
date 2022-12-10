#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
#define PI 3.141592653589793238462
#define rep(i,a,b) for (int i = a; i < b; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define db(x) cout<<#x<<" : "<<x<<endl;
#define debug(x) cerr<<#x<<" : "<<x<<endl;
#define pvec(v) cout<<"[";rep(x, 0, v.size()){cout<<v[x];if(x<v.size()-1)cout<<" ";}cout<<"]"<<endl;
#else
#define pvec(v) ;rep(x, 0, v.size()){cout<<v[x];if(x<v.size()-1)cout<<" ";}cout<<endl;
#define db(x)
#define debug(x)
#endif
#define getVal(c) (c-'a'+1)

const int N = 0;

// Actual Classes Per Week : 37 i.e 7.4 Classes Per Day

int minAttendance = 75;
int totalClasses; // Total Classes Held
int classesPresent; // Number Of Classes present 

int classCountPerDay = 7;


int targetAttendance = 90;

float GetPercentage(int _present, int total) {
	
	float _percentage = ((float)_present / (float) total) * 100;
	
	return _percentage;
}
 

pi GetContinuousLeaves(float _present, float _total) {
	//The Number Of Continuous Leaves Which Can Be taken So that Attendance Is Above 75
	int conLeaves = 0;
	
	int presentC = classesPresent;
	int totalC = totalClasses;
	
	float tAttendance = GetPercentage(presentC, totalClasses);
	
	
	int cnt = 0;
	
	while(tAttendance > minAttendance) {
		
		totalC++;
		tAttendance = GetPercentage(presentC, totalC);
		cnt++;
	} 
	
	int leaveDays = cnt / classCountPerDay;
	
	return MP(cnt, leaveDays);
}

pi GetNumberOfClassesToPresent(float _present, float _total) {
	
	float _percentage = GetPercentage(_present, _total);	
	
	int classCnt = 0;
	
	while(_percentage < minAttendance) {
		_present++;
		_total++;
		
		_percentage = GetPercentage(_present, _total);
		classCnt++;
	}
	
	int daysCnt = classCnt / classCountPerDay;
	
	return MP(classCnt, daysCnt);
}

pi GetClassCountToReachTarget(float _current, float _total) {
	//Edge Case
	if(targetAttendance >= 100) {
		return MP(-1, -1);
	}
	
	float _percentage = GetPercentage(_current, _total);
	
	int classCnt = 0;
	
	while(_percentage < targetAttendance) {
		
		_current++;
		_total++;
		
		_percentage = GetPercentage(_current, _total);
		
		classCnt++;
	}
	
	return MP(classCnt, classCnt/classCountPerDay);
}

string GetFormattedString(int classCnt) {
	
	int dayCnt = classCnt / classCountPerDay;
	
	// string str = classCnt + (" Classes, " + " or ") + dayCnt + " days";
	stringstream stream;
	stream << classCnt << " Classes, or " << dayCnt << " days";
	
	return stream.str();
}

void Solution(){
		
	
	
	// cout << "Enter Present Days: ";
	cin >> classesPresent;
	
	// cout << "Enter Total Days: ";
	cin >> totalClasses;
	
	
	float percentage = ((float)classesPresent / (float)totalClasses) * 100;
	pi conLeaves = GetContinuousLeaves(classesPresent, totalClasses);
	pi conPresent = GetNumberOfClassesToPresent(classesPresent, totalClasses);
	pi reqClasses = GetClassCountToReachTarget(classesPresent, totalClasses);
	
	cout << "Classes Present: " << classesPresent << "\n";
	cout << "Total Classes: " << totalClasses << "\n";
	cout << "Current Attendance: " << percentage << "%" << "\n";
	
	cout << "Req Classes to Reach " << targetAttendance << "% : " << GetFormattedString(reqClasses.F) << "\n";
	cout << "Con_Leaves : " << GetFormattedString(conLeaves.F) << "\n";
	cout << "Con_Present: " << GetFormattedString(conPresent.F) << "\n";
}


signed int main(){
	
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    #endif
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--){
		Solution();
	}
	return 0;
}