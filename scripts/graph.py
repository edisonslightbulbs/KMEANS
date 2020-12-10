#!/usr/bin/env python

import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import os
pwd = os.getcwd()


# dataset resources :
iris = pwd + "/resources/iris.csv"
unclustered = pwd + "/resources/input.csv"
clustered = pwd + "/resources/output.csv"


# 2D data set (a random data set):

# before clustering
df = pd.read_csv(unclustered, header=None)
df.columns = ["x", "y"]
sns.scatterplot(x=df["x"], y=df["y"])
plt.title("Before clustering")

# after clustering
plt.figure()
df = pd.read_csv(clustered)
sns.scatterplot(x=df.x, y=df.y, hue=df.label,
                palette=sns.color_palette("hls", n_colors=3))
plt.xlabel("x")
plt.ylabel("y")
plt.title("After clustering")


# 3D data set (infamous iris):

# before clustering
df = pd.read_csv(iris)     # import data (data frame)
sns.set(style="darkgrid")  # use dark theme
fig = plt.figure()         # create top level container for plot elements

# add axes to the figure in subplot arrangement
ax = fig.add_subplot(111, projection='3d')

# relative headings, atop the '*.csv' columns
x = df['sepal_length']
y = df['sepal_width']
z = df['petal_length']

# figure labels
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

# draw scatter plot
ax.scatter(x, y, z)

# show scatter plot
plt.show()
