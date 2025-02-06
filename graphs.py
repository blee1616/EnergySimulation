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
    arrcosts.append(line)

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