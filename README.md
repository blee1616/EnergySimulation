Electricity Usage Simulation

Overview

This project simulates household electricity usage by tracking power consumption for various appliances over a year. It generates monthly cost data and energy usage per appliance, which is then visualized using Python.

Features

Simulates electricity consumption of household appliances.

Calculates daily and monthly energy usage.

Tracks the cost of electricity usage based on peak and off-peak rates.

Outputs results into text files (MonthlyCosts.txt and JoulesPerAppliance.txt).

Visualizes monthly cost distribution and appliance-wise energy consumption using bar and pie charts.

Files

C++ Code Files:

main.cpp: The main program that simulates electricity usage and calculates costs.

MonthlyCosts.txt: Stores the monthly electricity costs.

JoulesPerAppliance.txt: Stores energy usage per appliance.

Python Visualization:

visualization.py: Reads data from text files and generates bar and pie charts using matplotlib and numpy.

Installation & Usage

Requirements:

C++ compiler (e.g., g++, clang)

Python 3.x

Required Python libraries: numpy, matplotlib

Running the Simulation:

Compile and run the C++ program:

g++ -o electricity_simulation main.cpp
./electricity_simulation

Run the Python visualization script:

python visualization.py

Output

Monthly Costs Visualization: A bar chart and pie chart displaying energy costs per month.

Appliance Usage Visualization: A horizontal bar chart and pie chart showing energy consumption per appliance
