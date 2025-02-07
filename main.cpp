#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <numeric>

std::vector<double> monthCosts;
std::vector<double> appliancesUsage(13);

std::ofstream MonthlyCost; //file used to store costs per month
std::ofstream JoulesPerAppliance; //file used to store how many Joules were used per Appliance

class Appliance {
public:
    std::string name;
    double min_watts, max_watts;
    int start_time, end_time;

    Appliance(std::string name, double min_watts, double max_watts, int start_time, int end_time)
        : name(name), min_watts(min_watts), max_watts(max_watts), start_time(start_time), end_time(end_time) {}

    double get_random_wattage() { //uses uniform distribution in order to generate random wattage for electrical appliance given minimum and maximum amount of watts used.
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min_watts, max_watts);
        return dis(gen);
    }

    bool is_operating(int hour) { //checks if appliance is on at that time
        return start_time <= hour && hour < end_time;
    }
};

class ElectricityUsage {
public:
    std::vector<Appliance> appliances;
    std::vector<double> usage_matrix;

    ElectricityUsage(std::vector<Appliance> appliances) : appliances(appliances) {
        std::vector<double> usage_matrix;
    }

    std::vector<double> calculate_daily_usage() { //calculates the  daily usage based on appliance watts
        for (int hour = 0; hour < 24; hour++) {
            double total_usage = 0.0;

            for (int i = 0; i < appliances.size(); i++) {
                if (appliances[i].is_operating(hour)) {
                    double appliance_wattage = appliances[i].get_random_wattage();
                    total_usage += appliance_wattage;
                    appliancesUsage[i] += appliance_wattage; //tracks how many Joules were used per appliance
                }
            }
            usage_matrix.push_back(total_usage);
        }
        return usage_matrix;
    }
};

class EnergyReport {
public:
    std::vector<double> usage_data;
    double peak_rate, off_peak_rate;
    int month_number;

    EnergyReport(std::vector<double> usage_data, int month_number, double peak_rate = 0.30, double off_peak_rate = 0.20)
        : usage_data(usage_data), month_number(month_number), peak_rate(peak_rate), off_peak_rate(off_peak_rate) {}

    double calculate_cost_per_month() {
        int days_in_month = (month_number == 1) ? 28 : 30;
        double cost = 0.0;
        for (int day = 0; day < days_in_month; day++) {
            for (int hour = 0; hour < 24; hour++) {
                double rate = (hour >= 17 && hour <= 19) ? peak_rate : off_peak_rate;
                cost += usage_data[hour] * rate / 1000; // Convert watts to kWh
            }
        }
        return cost;
    }
};

int main() {
    std::vector<Appliance> appliances = {
        Appliance("Fridge", 300, 450, 0, 24),
        Appliance("Mini Fridge", 30, 70, 0, 24),
        Appliance("Stove", 1000, 2000, 9, 10),
        Appliance("Toaster & Microwave", 800, 1600, 8, 14),
        Appliance("Oven", 2000, 3000, 17, 18),
        Appliance("Phone(s) & Tablet(s)", 15, 50, 0, 24),
        Appliance("Laptop(s)", 30, 90, 0, 24),
        Appliance("PC(s)", 50, 350, 0, 24),
        Appliance("TV(s)", 50, 100, 8, 18),
        Appliance("Lightbulbs & Lamps", 20, 80, 0, 24),
        Appliance("Washing Machine", 800, 1000, 17, 18),
        Appliance("Dryer", 1800, 3200, 18, 19),
    };
    for (int month = 0; month < 12; month++) {
        if (month == 6) {
            appliances.push_back(Appliance("AC",4000,5000,10,18));
        }
        else if (month == 9) {
            appliances.pop_back();
        }

        ElectricityUsage usage(appliances);
        std::vector<double> hourly_usage = usage.calculate_daily_usage();

        EnergyReport report(hourly_usage, month);
        monthCosts.push_back(report.calculate_cost_per_month());
    }
    
    MonthlyCost.open("MonthlyCosts.txt");
    JoulesPerAppliance.open("JoulesPerAppliance.txt");

    std::cout << "Monthly Costs:";
    for (double cost : monthCosts) {
        std::cout << " " << cost;
    }

    for (int i = 0; i < 11; i++) {
        MonthlyCost << monthCosts[i] << std::endl;
    }
    MonthlyCost << monthCosts[11];
    for (int i = 0; i < 12; i++) {
        JoulesPerAppliance << appliancesUsage[i] << std::endl;
    }
    JoulesPerAppliance << appliancesUsage[12];
    MonthlyCost.close();
    JoulesPerAppliance.close();
    std::cout << std::endl;
    return 0;
}
