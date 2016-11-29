#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

enum Types {
	CREATE,
	DELETE,
	DROP,
	INSERT,
	SELECT
};

struct Rect {
	double min[2];
	double max[2];
	
	Rect() {}

	Rect(double a_minX, double a_minY, double a_maxX, double a_maxY) {
		min[0] = a_minX;
		min[1] = a_minY;
		max[0] = a_maxX;
		max[1] = a_maxY;
	}  
};

struct parse_result {
	string q_type;
	string t_name;
	Rect rect;
	char spatial;
	

};





typedef pair<double, double> Point;
typedef vector<Point> Polygon;

const unordered_map<string, int> Name2Type = {
	{"create", CREATE},
	{"delete", DELETE},
	{"drop", DROP},
	{"insert", INSERT},
	{"select", SELECT}
};

void create_table(string t_name, string geo_name, string attr_name, string attr_type) {
	cout << "create_table" << endl;
	cout << t_name << endl;
	cout << geo_name << endl;
	cout << attr_name << endl;
	cout << attr_type << endl;
}

void drop_table(string t_name) {

}

void insert_query(string t_name, Polygon p, string value) {
	cout << "insert_query" << endl;
	cout << t_name << endl;
	cout << value << endl;
}

void parser(string query);


//
void parser(string query) {
	istringstream iss(query);
	string type;
	iss >> type;
	transform(type.begin(), type.end(), type.begin(), ::tolower);
	Types t = (Types)Name2Type.at(type);

	string tmp;
	vector<string> s_list;
	while (iss >> tmp) {
		s_list.push_back(tmp);
	}
	switch(t) {
		case CREATE: {
			s_list[2].erase(s_list[2].begin());
			s_list[7].erase(s_list[7].end()-1);
			create_table(s_list[1], s_list[2], s_list[6], s_list[7]);
			break;
		}
		case DROP: {
			drop_table(s_list[1]);
			break;
		}
		case INSERT: {
			s_list[5].erase(s_list[5].end()-1);
			s_list[7].erase(s_list[7].end()-1);
			s_list[9].erase(s_list[9].end()-1);
			s_list[11].erase(s_list[11].end()-1);
			s_list[15].erase(s_list[15].end()-2, s_list[11].end());
			s_list[15].erase(s_list[15].begin());

			Polygon p;
			p.push_back(Point(stod(s_list[4]), stod(s_list[5])));
			p.push_back(Point(stod(s_list[6]), stod(s_list[7])));
			p.push_back(Point(stod(s_list[8]), stod(s_list[9])));
			p.push_back(Point(stod(s_list[10]), stod(s_list[11])));

			insert_query(s_list[1], p, s_list[15]);
			
			break;
		}
		case SELECT: {
			
		}

		case DELETE:
			break;
			


		
	}


	












}