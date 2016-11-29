#include "parser.h"

using namespace std;

int main() {
	parser("CREATE TABLE gis (g GEOMETRY NOT NULL, color VARCHAR(12), SPATIAL INDEX(g)) ENGINE=MyISAM;\n");
	parser("INSERT INTO gis VALUES\n(PolygonFromText('POLYGON(( 10 10, 20 10, 20 20, 10 20, 10 10 ))'), 'red')\n");

// 	parser("SELECT COUNT(*) FROM gis1 WHERE ST_CONTAINS(PolygonFromText('POLYGON((";
// 		for (int j = 0; j <= 3; j++) {
// 			fs1 << p[j].first << " " << p[j].second << ", ";
// 		}
// 		fs1 << p[0].first << " " << p[0].second << "))'), g) AND ";
// 		fs1 << "color='red';\n";
// }
}