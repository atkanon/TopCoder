/**
* SRM300 division2 easy
*/

import java.util.*;

public class Taxi{
	public double maxDis(int maxX, int maxY, int taxiDis){
		double _max = Math.max(maxX, maxY), _min = maxX+maxY-_max;
		if(_max > taxiDis) return taxiDis;
		if(_max+_min < taxiDis) return -1.0;
		return Math.sqrt(Math.pow(_max, 2)+Math.pow((taxiDis-_max), 2));
	}
}