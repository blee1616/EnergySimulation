import numpy as np
import matplotlib.pyplot as plt

# Data from the text file
month_f = open("MonthlyCosts.txt", "r")
months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
arrcosts = []
while True:
    line = month_f.readline()
    if not line:
        break
    arrcosts.append(float(line))

costs = np.array(arrcosts)

# Compute percentages
total = np.sum(costs)
percentages = (costs / total) * 100

# Bar chart
plt.figure(figsize=(10, 5))
plt.bar(months, percentages, color='skyblue')
plt.xlabel("Months")
plt.ylabel("Usage Percentage (%)")
plt.title("Monthly Usage Percentage")
plt.xticks(rotation=45)
plt.show()

# Pie chart
plt.figure(figsize=(7, 7))
plt.pie(percentages, labels=months, autopct='%1.1f%%', colors=plt.cm.tab10.colors, startangle=140)
plt.title("Usage Distribution by Month")
plt.show()

appliances = ["Refrigerator", "Mini Fridge", "Stove", "Toaster & Microwave", "Oven",
    "Phone(s) & Tablet(s)", "Laptop(s)", "PC(s)", "TV(s)", "Lightbulbs (including lamps)",
    "Washing Machine", "Dryer", "AC"]

energy_usage_array = []
appliance_f = open("JoulesPerAppliance.txt","r")
while True:
    line = appliance_f.readline()
    if not line:
        break
    energy_usage_array.append(float(line))

energy_usage = np.array(energy_usage_array)

# Create bar chart
plt.figure(figsize=(12, 6))
plt.barh(appliances, energy_usage, color='skyblue')
plt.xlabel("Energy Usage (kWh)")
plt.ylabel("Appliance")
plt.title("Energy Consumption by Household Appliance")
plt.gca().invert_yaxis()  # Invert y-axis for better readability
plt.grid(axis='x', linestyle='--', alpha=0.7)
plt.show()

# Create pie chart
plt.figure(figsize=(8, 8))
plt.pie(energy_usage, labels=appliances, autopct='%1.1f%%', startangle=140, colors=plt.cm.Paired.colors)
plt.title("Percentage Energy Consumption by Appliance")
plt.show()