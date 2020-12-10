#!/usr/bin/env python

import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import os

pwd = os.getcwd()

csv_input = pwd + "/src/input.csv"
csv_output = pwd + "/src/output.csv"

unclustered = csv_input
clustered = csv_output

# Before clustering
df = pd.read_csv(unclustered, header=None)
df.columns = ["x", "y"]
sns.scatterplot(x=df["x"], y=df["y"])
plt.title("Before clustering")

# After clustering
plt.figure()
df = pd.read_csv(clustered)
sns.scatterplot(x=df.x, y=df.y, hue=df.label,
                palette=sns.color_palette("hls", n_colors=5))

plt.xlabel("x")
plt.ylabel("y")
plt.title("After clustering")

plt.show()
