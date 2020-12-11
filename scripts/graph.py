#!/usr/bin/env python

import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import os
from matplotlib.colors import ListedColormap

pwd = os.getcwd()


# DATASET RESOURCES:
data_2d_input = pwd + "/resources/2d_input.csv"
data_2d_output = pwd + "/resources/2d_output.csv"

data_3d_input = pwd + "/resources/3d_input.csv"
data_3d_output = pwd + "/resources/3d_output.csv"

sns.set(style="darkgrid")       # use dark theme

###############################################################################

# BEFORE CLUSTERING:
df = pd.read_csv(data_2d_input, header=None)
df.columns = ["x", "y"]
sns.scatterplot(x=df["x"], y=df["y"])
plt.title("Before clustering")

###############################################################################

# AFTER CLUSTERING:
plt.figure()
df = pd.read_csv(data_2d_output)
sns.scatterplot(x=df.x, y=df.y, hue=df.label,
                palette=sns.color_palette("hls", n_colors=3))
plt.xlabel("x")
plt.ylabel("y")
plt.title("After clustering")

###############################################################################

# BEFORE CLUSTERING:
# import data
df = pd.read_csv(data_3d_input, header=None)

# declare columns (needs to match the number of cols in input file)
df.columns = ["sepal_length", "sepal_width", "petal_length"]

# figure container
fig = plt.figure()

# add axes to the figure in subplot arrangement
ax = fig.add_subplot(111, projection='3d')

# figure labels
ax.set_xlabel("sepal length")
ax.set_ylabel("sepal width")
ax.set_zlabel("petal length")

# draw scatter plot
ax.scatter(df["sepal_length"], df["sepal_width"], df["petal_length"])

###############################################################################

# AFTER CLUSTERING:
# import data
df = pd.read_csv(data_3d_output)

# figure container
fig = plt.figure()

# add axes to the figure in subplot arrangement
ax = fig.add_subplot(111, projection='3d')

x = df["x"]
y = df["y"]
z = df["z"]
c = df["label"]

# figure labels
ax.set_xlabel("sepal length")
ax.set_ylabel("sepal width")
ax.set_zlabel("petal length")

# get colormap from seaborn see:
# https://stackoverflow.com/questions/52285104/3d-scatterplots-in-python-with-hue-colormap-and-legend
cmap = ListedColormap(sns.color_palette("hls", n_colors=3))

# draw scatter plot
#ax.scatter(x, y, z)

# plot
sc = ax.scatter(x, y, z, s=25, c=c, marker='o', cmap=cmap)

# legend
plt.legend(*sc.legend_elements(), bbox_to_anchor=(1.05, 1), loc=2)


# show scatter plot
plt.show()
