// problem source: https://leetcode.com/problems/design-underground-system/
class UndergroundSystem {
public:
    struct CustomerInfo {
        string start_station;
        string end_station;
        int start_time;
        int end_time;
    };

    struct StationInfo {
        string start_station;
        string end_station;
        vector<int> travel_time;
    };

    unordered_map<int, CustomerInfo> customer_info;
    vector<StationInfo> station_info;

    UndergroundSystem() {
        customer_info.clear();
        station_info.clear();
    }

    void checkIn(int id, string stationName, int t) {
        customer_info[id].start_station = stationName;
        customer_info[id].start_time = t;
    }

    void updateStationInfo(int id) {
        int station_info_size = station_info.size();
        bool exist = false;
        for (int i = 0; i < station_info_size; i++) {
            if (station_info[i].start_station == customer_info[id].start_station &&
                station_info[i].end_station == customer_info[id].end_station) {
                station_info[i].travel_time.push_back(customer_info[id].end_time - customer_info[id].start_time);
                exist = true;
                break;
            }
        }
        if (!exist) {
            StationInfo individual_info;
            individual_info.start_station = customer_info[id].start_station;
            individual_info.end_station = customer_info[id].end_station;
            individual_info.travel_time.push_back(customer_info[id].end_time - customer_info[id].start_time);
            station_info.push_back(individual_info);
        }
    }

    void checkOut(int id, string stationName, int t) {
        customer_info[id].end_station = stationName;
        customer_info[id].end_time = t;
        updateStationInfo(id);
    }

    double getAverageTime(string startStation, string endStation) {
        double result;
        int sum = 0;
        int time_info_size;
        StationInfo found_info;
        int station_info_size = station_info.size();
        for (int i = 0; i < station_info_size; i++) {
            if (station_info[i].start_station == startStation &&
                station_info[i].end_station == endStation) {
                found_info = station_info[i];
                time_info_size = found_info.travel_time.size();
                break;
            }
        }
        for(int i = 0; i < time_info_size; i++)
            sum += found_info.travel_time[i];
        result = sum / (double)time_info_size;
        return result;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
